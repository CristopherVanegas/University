import { useState, useEffect } from "react";
import { useLoaderData, useNavigate, useOutletContext, useLocation } from "@remix-run/react";
import { ClientOnly } from "remix-utils";

import useSWR from "swr";
import axios from "axios";

import { crearOrden, obtenerOrden, fetchPayohone } from "../../models/pagos.server";

import { CookingIcon, PedidoIcon } from "../../svg/iconos";

import { infoLocal } from "../../helpers/infoLocales";

export const loader = async ({ request }) => {
    const url = new URL(request.url);
    const transaccion = url.searchParams.get("id");
    const clientTransactionId = url.searchParams.get("clientTransactionId");

    if (transaccion) {
        const infoDePago = await fetchPayohone(transaccion, clientTransactionId);
        return infoDePago;
    } else {
        const infoPago = { transactionStatus: "Efectivo", status: "Pedido Hecho Exitosamente" };
        return infoPago;
    }
};

export default function Pedido() {
    const { pedido, setCarrito } = useOutletContext();

    const [infoDePago, setInfoDePago] = useState({});
    const [realTimeData, setRealTimeData] = useState({}); // Estado local para almacenar los datos en tiempo real

    const datos = useLoaderData();

    const navigate = useNavigate();
    const location = useLocation();

    const token = typeof window !== "undefined" && localStorage.getItem("token");

    const queryString = location.search;
    const id_orden = queryString.split("clientTransactionId=")[1];

    useEffect(() => {
        setInfoDePago(datos);
    }, [datos]);

    useEffect(() => {
        async function fetchPedidos() {
            if (infoDePago?.transactionStatus === "Approved" || infoDePago?.transactionStatus === "Efectivo") {
                if (isNaN(id_orden)) {
                    const datos = await crearOrden(pedido, token);
                    setInfoDePago(datos);
                    setCarrito([]);
                    window.location = `/pedido?clientTransactionId=${datos.orden.id_orden}`;
                    return;
                } else {
                    const datos = await obtenerOrden(id_orden, token);
                    setInfoDePago(datos);
                    setCarrito([]);
                    return;
                }
            }

            if (infoDePago?.transactionStatus === "Canceled") {
                navigate("/error-tarjeta");
                return;
            }
        }
        fetchPedidos();
    }, [infoDePago?.transactionStatus]);

    let fetcher = () =>
        axios(`http://localhost:5000/api/ordenes/${id_orden}`).then((datos) => {
            // Actualizar el estado local con los datos en tiempo real
            setRealTimeData(datos.data);
            return datos.data;
        });

    const { data: datosOrden, error } = useSWR(`http://localhost:5000/api/ordenes/${id_orden}`, fetcher, {
        refreshInterval: 5000,
    });

    if (error) return <div>failed to load</div>;
    if (!datosOrden) return <div>loading...</div>;

    const local = pedido?.localComercial;

    return (
        <ClientOnly fallback={'Cargando...'}>
            {() => (
                <main>
                    <h1 className="text-3xl text-color-aloha text-center font-bold mb-1">Pedido</h1>
                    {infoDePago?.id_orden ? (
                        <p className="text-black px-10 font-bold text-center mb-10 uppercase">#{infoDePago?.id_orden}</p>
                    ) : (
                        <p className="text-center mb-10">Cargando...</p>
                    )}

                    <div className="mt-14">
                        <div className="bg-gray-300 rounded-full w-4/5 m-auto md:w-3/6">
                            <div style={{ width: `${realTimeData?.estado == "Creada" ? 2 : realTimeData?.estado == "Preparando" ? 48 : realTimeData?.estado == "Completado" ? 98 : 0}%` }}
                                className="rounded-full bg-color-aloha text-xs leading-none h-2"
                            >
                            </div>
                        </div>

                        <div className="flex justify-between w-4/5 m-auto md:w-3/6 -mt-10">
                            <div className="flex items-center justify-center bg-color-aloha sombra-aloha-roja h-14 w-16 md:w-20 my-2" style={{ borderRadius: "50%" }}>
                                <PedidoIcon tamaño={"w-8 h-8"} />
                            </div>

                            <div className={`flex items-center justify-center h-14 w-16 md:w-20 my-2 ${realTimeData?.estado == "Preparando" || realTimeData?.estado == "Completado" ? "bg-color-aloha sombra-aloha-roja" : "bg-gray-300"}`} style={{ borderRadius: "50%" }}>
                                <CookingIcon tamaño={"w-8 h-8"} />
                            </div>

                            <div className={`flex items-center justify-center h-14 w-16 md:w-20 my-2 ${realTimeData?.estado == "Completado" ? "bg-color-aloha sombra-aloha-roja" : "bg-gray-300"}`} style={{ borderRadius: "50%" }}>
                                <img src="https://res.cloudinary.com/dqtirelyc/image/upload/v1682221831/Bolon_SVG_c6db3o.svg" alt="Icono de Bolon" className="w-10 h-10" />
                            </div>
                        </div>

                        <div className="flex justify-between w-5/6 md:w-3/6 m-auto">
                            <p className="font-bold">Recibido</p>
                            <p className="font-bold">Preparando</p>
                            <p className="font-bold mb-4">Recógelo</p>
                        </div>

                        <iframe title={`Local ${local}`} src={infoLocal[local]?.src} className="w-5/6 m-auto" height="400" style={{ border: "0" }} allowFullScreen="" loading="lazy" referrerPolicy="no-referrer-when-downgrade"></iframe>

                        <a className="flex justify-center" href={infoLocal[local]?.tel}>
                            <button className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 font-bold text-center my-7">Llamar al local</button>
                        </a>
                    </div>
                </main>
            )}
        </ClientOnly>
    );
}

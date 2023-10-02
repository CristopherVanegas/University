import { Link, useOutletContext } from "@remix-run/react"
import { ClientOnly } from "remix-utils";

import CardProductoCarrito from "../components/card-producto-carrito"

export default function Carrito() {
    const { carrito, setCarrito, auth, eliminarProducto } = useOutletContext();
    let total = 0;

    carrito ? carrito.map( producto =>{
        producto.cantidad == 0 ? eliminarProducto(producto._id) : ''
    }) : [];

    if (!carrito || !carrito.length) {
        return (
            <ClientOnly fallback={'Cargando...'}>
                {() => (
                    <>
                        <h1 className="text-3xl text-color-aloha text-center font-bold">Carrito</h1>
                        <p className="text-center mt-4">No hay productos en el carrito</p>
                    </>
                )}
            </ClientOnly>
        )
    }

    carrito ? carrito.forEach((producto) => {
        total += producto.cantidad * producto.precio;
    }) : [];

    if(isNaN(total)){
        setCarrito([]);
    }    

    return (
        <ClientOnly fallback={'Cargando...'}>
            {() => (
                <>
                    <h1 className="text-3xl text-color-aloha text-center font-bold">Carrito</h1>
                    {carrito.map((producto) => (
                        <CardProductoCarrito key={producto.id_producto} producto={producto} />
                    ))}

                    <div className="text-center mt-5 mb-2">
                        <Link
                            to={`${auth.email ? "/pagar" : "/login"}`}
                            className="text-white uppercase text-lg bg-color-aloha rounded-lg sombra-aloha-roja w-3/6 py-1 px-3 m-auto font-bold text-center"
                        >{`IR A PAGAR`}</Link>
                    </div>
                </>
            )}
        </ClientOnly>
    )
}

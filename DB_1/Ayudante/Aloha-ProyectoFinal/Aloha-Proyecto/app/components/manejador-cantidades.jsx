import { useState, useEffect } from "react";
import { useOutletContext } from "@remix-run/react";

export default function ManejadorCantidades({ producto }) {

    const { agregarCarrito, actualizarCarrito, eliminarProducto } = useOutletContext();
    const { nombre, precio, imagen, id_producto } = producto;

    const [cantidad, setCantidad] = useState(producto.cantidad);

    const [mostrarManejador, setMostrarManejador] = useState(false);

    // AGREGA CARRITO AL CONTEX, EN EL STATE, ACTUALIZADA LA CANTIDAD Y MUESTRA LOS MANEJADORES
    const agregarCarritoState = (nombre, precio, id_producto) => {
        const producto = {
            nombre,
            precio,
            id_producto,
            cantidad,
            imagen
        }
        agregarCarrito(producto)
        setMostrarManejador(true);
        setCantidad(cantidad + 1)
    }

    // ACTUALIZA EL CARRITO CADA VEZ QUE CAMBIA SU CANTIDAD
    useEffect(() => {
        const producto = { //Ya que solo voy a modificar la cantidad no necesito pasarle los demás parametros, porque lo identidica por el ID
            id_producto,
            cantidad
        }
        actualizarCarrito(producto)

    }, [cantidad])

    return (
        <>
            {mostrarManejador || cantidad >= 1 ? (
                <div className="producto-card">
                    <div className="flex gap-3 items-center">
                        <div onClick={() => { cantidad <= 0 ? "" : setCantidad(cantidad - 1) }}>
                            {cantidad <= 1 ? (
                                <div
                                    onClick={() => {
                                        eliminarProducto(producto.id_producto)
                                        setMostrarManejador(false);
                                        producto.cantidad = 0
                                    }}
                                    className="bg-color-aloha px-1 rounded-md flex items-center sombra-aloha-roja text-white font-bold text-xl py-125 lg:text-3xl lg:px-2 h-10"
                                >
                                    <svg xmlns="http://www.w3.org/2000/svg" className="w-5 h-5" viewBox="0 0 512 512"><path fill="none" d="M296 64h-80a7.91 7.91 0 0 0-8 8v24h96V72a7.91 7.91 0 0 0-8-8Z" />
                                        <path fill="#fff" d="M432 96h-96V72a40 40 0 0 0-40-40h-80a40 40 0 0 0-40 40v24H80a16 16 0 0 0 0 32h17l19 304.92c1.42 26.85 22 47.08 48 47.08h184c26.13 0 46.3-19.78 48-47l19-305h17a16 16 0 0 0 0-32ZM192.57 416H192a16 16 0 0 1-16-15.43l-8-224a16 16 0 1 1 32-1.14l8 224A16 16 0 0 1 192.57 416ZM272 400a16 16 0 0 1-32 0V176a16 16 0 0 1 32 0Zm32-304h-96V72a7.91 7.91 0 0 1 8-8h80a7.91 7.91 0 0 1 8 8Zm32 304.57A16 16 0 0 1 320 416h-.58A16 16 0 0 1 304 399.43l8-224a16 16 0 1 1 32 1.14Z" />
                                    </svg>
                                </div>
                            ) : (
                                <div onClick={() => { cantidad <= 0 ? "" : setCantidad(cantidad - 1) }}
                                    className="bg-color-aloha px-2 rounded-md flex items-center sombra-aloha-roja text-white font-bold text-xl"
                                >
                                    <p className="font-bold text-xl md:mt-0.5 lg:text-3xl">-</p>
                                </div>
                            )}
                        </div>

                        <p className="text-black font-bold text-lg lg:text-xl">{cantidad}</p>

                        <div onClick={() => { 
                            setCantidad(cantidad + 1)
                        }}
                            className="bg-color-aloha px-2 rounded-md flex items-center sombra-aloha-roja text-white font-bold text-xl"
                        >
                            <p className="font-bold text-xl md:mt-0.5 lg:text-3xl">+</p>
                        </div>

                    </div>
                </div>
            ) : (
                <div className="producto-card">
                    <div className="flex">
                        <div className="bg-color-aloha p-1 rounded-md flex items-center sombra-aloha-roja margin-le lg:text-3xl lg:py-2.5 lg:px-2" onClick={() => { agregarCarritoState(nombre, precio, id_producto) }}>
                            <svg xmlns="http://www.w3.org/2000/svg" className="w-5 h-5" viewBox="0 0 256 256">
                                <path fill={"#FFF"} d="m223.9 65.4l-12.2 66.9a24 24 0 0 1-23.6 19.7h-116l4.4 24H184a24 24 0 1 1-24 24a23.6 23.6 0 0 1 1.4-8h-58.8a23.6 23.6 0 0 1 1.4 8a24 24 0 1 1-42.2-15.6L34.1 32H16a8 8 0 0 1 0-16h18.1a16 16 0 0 1 15.7 13.1L54.7 56H216a7.9 7.9 0 0 1 6.1 2.9a7.7 7.7 0 0 1 1.8 6.5Z" />
                            </svg>
                        </div>
                    </div>
                </div>
            )}
        </>
    )
}

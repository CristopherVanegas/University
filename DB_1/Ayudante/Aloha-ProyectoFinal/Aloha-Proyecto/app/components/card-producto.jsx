import { useState, useEffect } from "react";
import { ClientOnly } from "remix-utils"
import ManejadorCantidades from "./manejador-cantidades";

export default function CardProducto({ producto }) {
    const { nombre, imagen, precio } = producto;

    return (
        <ClientOnly>
            {() => (
                <>
                    <div className={`flex-col py-5 m-3 rounded-2xl sombra-aloha card-producto`}>

                        <img src={imagen} alt={`Imagen ${nombre}`} className="margin-producto" />

                        <div className="px-6 -mt-10">

                            <h2 className={`text-black text-titulo-aloha font-bold`}>{nombre}</h2>

                            <p className='text-green-600 font-bold text-subtitulo-aloha pt-1'>Disponible</p>
                            <div className="flex gap-1 items-center">
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill={"#FFC700"} className="w-4 h-4">
                                    <path fillRule="evenodd" d="M10.788 3.21c.448-1.077 1.976-1.077 2.424 0l2.082 5.007 5.404.433c1.164.093 1.636 1.545.749 2.305l-4.117 3.527 1.257 5.273c.271 1.136-.964 2.033-1.96 1.425L12 18.354 7.373 21.18c-.996.608-2.231-.29-1.96-1.425l1.257-5.273-4.117-3.527c-.887-.76-.415-2.212.749-2.305l5.404-.433 2.082-5.006z" clipRule="evenodd" />
                                </svg>
                                <p className="font-semibold lg:mr-5 lg:text-lg">4.9</p>
                            </div>

                            <div className="flex justify-between mt-5 font-bold text-titulo-aloha text-black">
                                <p className="text-xl md:text-2xl">${Number(precio)}</p>
                            </div>

                            <ManejadorCantidades producto={producto} />
                        </div>

                    </div>
                </>
            )}
        </ClientOnly>
    )
}

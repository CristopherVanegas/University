import { useOutletContext, Link, useNavigate } from "@remix-run/react";
import { useEffect, useState } from "react";
import { ClientOnly } from "remix-utils";

import CardPerfil from "~/components/card-perfil"

import { HelpIcon } from "svg/iconos"

export default function Perfil() {
    const { auth, setAuth } = useOutletContext();

    const password = '*'.repeat(10);
    const navigate = useNavigate();

    useEffect(() => {
        if (auth.length === 0 || auth == undefined || auth == []) navigate("/login")
    }, [])

    const cerrarSesion = ()=>{
        localStorage.clear();
        setTimeout(()=>{
            window.location = "/login"
        }, 500)
    }

    return (
        <ClientOnly fallback={'Cargando...'}>
            {() => (
                <main className="w-4/5 md:w-2/5 m-auto">
                    <h1 className="text-3xl text-color-aloha text-center font-bold mt-20 md:mt-28">Perfil</h1>
                    <p className="text-black px-10 font-bold text-center mb-10 text-sm">Acumula puntos por tus compras</p>

                    <div className="flex justify-center space-x-4 my-2 items-center mb-10">
                        <CardPerfil key={'Ayuda'} icono={<HelpIcon />} titulo={'Ayuda'} enlace={'https://wa.link/l6cdmq'} />
                    </div>

                    <div className="m-auto space-y-3">
                        <h3 className="font-bold text-base mt-2">Correo Electrónico</h3>
                        <div className="sombra-aloha rounded-xl h-12 w-full bg-white flex items-center">
                            <p className={`text-gray-aaa px-3`}>{auth?.email || ''}</p>
                        </div>
                        <Link to={'/cambiar-correo'} className="text-color-aloha flex justify-end font-bold text-xs mt-2">Cambiar Correo</Link>
                    </div>

                    <div className="m-auto space-y-3">
                        <h3 className="font-bold text-base mt-2">Contraseña</h3>
                        <div className="sombra-aloha rounded-xl h-12 bg-white flex items-center">
                            <p className={`text-gray-aaa px-3`}>{password}</p>
                        </div>
                        <Link to={'/cambiar-password'} className="text-color-aloha text-end font-bold text-xs mt-2 flex justify-end">Cambiar Contraseña</Link>
                    </div>

                    <div className="text-center my-7" onClick={()=> {cerrarSesion()}}>
                        <input type="submit" value='Cerrar Sesión' className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 m-auto font-bold" />
                    </div>
                </main>
            )}
        </ClientOnly>
    )
}

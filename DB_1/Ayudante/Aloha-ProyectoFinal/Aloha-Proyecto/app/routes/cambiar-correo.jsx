import { useState, useEffect } from "react"
import { Link, useOutletContext, useNavigate } from "@remix-run/react";

import axios from "axios";

import InputForm from "~/components/input-form";
import Alerta from "~/components/alerta";

export default function CambiarCorreo() {

    const [nuevoCorreo, setNuevoCorreo] = useState('');
    const [alerta, setAlerta] = useState({});
    const { auth } = useOutletContext();

    const navigate = useNavigate();

    useEffect(() => {
        if (auth.length === 0 || auth == undefined) navigate("/login")
    }, [])

    const token = typeof window !== 'undefined' && localStorage.getItem('token');

    const config = {
        headers: {
            "Content-Type": "application/json",
            Authorization: `Bearer ${token}`
        }
    }

    const handleSubmit = async e => {
        e.preventDefault();

        //Validación de los campos
        if ([nuevoCorreo].includes('')) {
            setAlerta({
                msg: 'El campo de correo es obligatorio',
                error: true
            })
            return
        }

        //Enviar petición
        try {
            const email = auth.email;

            const { data } = await axios.post(`http://localhost:5000/api/usuarios/cambiar-correo`, { email, nuevoCorreo }, config);

            setAlerta({
                msg: data.msg,
                error: false
            })

            auth.email = nuevoCorreo

        } catch (error) {
            console.log(error);
            setAlerta({
                msg: 'Hubo un error al actualizar tu correo',
                error: true
            })
        }
    }

    const { msg } = alerta;

    return (
        <main className="xs:mt-20 sm:mt-24 md:mt-0">
            <div className="m-auto">
                <h1 className="text-3xl text-color-aloha text-center font-bold mb-10">Cambiar Correo</h1>

                {msg && (
                    <div className="-mt-6">
                        <Alerta alerta={alerta} />
                    </div>
                )}

                <form onSubmit={handleSubmit}>
                    <InputForm id={'email'} descripcion={'Nuevo Correo Electrónico'} tipo={'email'} modificador={setNuevoCorreo} valor={nuevoCorreo} color={'text-black'} />

                    <div className="w-4/5 md:w-2/5 m-auto">
                        <Link
                            className="uppercase mt-16 text-color-aloha font-bold"
                            to={'/perfil'}
                        >{'<Volver'}</Link>
                    </div>

                    <div className="text-center mt-20">
                        <input type="submit" value='Guardar cambios' className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1.5 m-auto font-bold" />
                    </div>

                </form>
            </div>
        </main>
    )
}

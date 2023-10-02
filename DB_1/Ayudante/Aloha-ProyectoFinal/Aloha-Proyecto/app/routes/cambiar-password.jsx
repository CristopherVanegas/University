import { useState, useEffect } from "react";
import { Link, useOutletContext, useNavigate } from "@remix-run/react";

import axios from "axios";
import Alerta from "~/components/alerta";
import InputForm from "~/components/input-form";

export default function CambiarPassword() {
    const [password, setPassword] = useState("");
    const [nuevoPassword, setnuevoPassword] = useState("");
    const [confirmarPassword, setConfirmarPassword] = useState("");
    const [alerta, setAlerta] = useState({});
    const { auth } = useOutletContext();

    const navigate = useNavigate();

    useEffect(() => {
        if (auth.length === 0 || auth == undefined) navigate("/login")
    }, [])

    const token = typeof window !== "undefined" && localStorage.getItem("token");

    const config = {
        headers: {
            "Content-Type": "application/json",
            Authorization: `Bearer ${token}`,
        },
    };

    const handleSubmit = async (e) => {
        e.preventDefault();

        // Validación de los campos
        if ([password, nuevoPassword, confirmarPassword].includes("")) {
            setAlerta({
                msg: "Todos los campos son obligatorios",
                error: true,
            });
            return;
        }

        if (nuevoPassword !== confirmarPassword) {
            setAlerta({
                msg: "Las contraseñas no coinciden",
                error: true,
            });
            return;
        }

        // Enviar petición
        try {
            const email = auth.email;

            console.log(email);

            const { data } = await axios.post(
                `http://localhost:5000/api/usuarios/cambiar-password`,
                { email, password, nuevoPassword },
                config
            );

            setAlerta({
                msg: data.msg,
                error: false,
            });

        } catch (error) {
            console.log(error);
            setAlerta({
                msg: error.response.data.msg,
                error: true
            })
        }
    }
    const { msg } = alerta;

    return (
        <main className="xs:mt-20 sm:mt-24 md:mt-0">
            <div className="m-auto">
                <h1 className="text-3xl text-color-aloha text-center font-bold mb-10">Cambiar Contraseña</h1>

                {msg && (
                    <div className="-mt-6">
                        <Alerta alerta={alerta} />
                    </div>
                )}

                <form onSubmit={handleSubmit}>

                    <InputForm id={'password-antiguo'} descripcion={'Contraseña actual'} tipo={'password'} modificador={setPassword} valor={password} color={'text-black'} />

                    <InputForm id={'password-nuevo'} descripcion={'Nueva Contraseña'} tipo={'password'} modificador={setnuevoPassword} valor={nuevoPassword} color={'text-black'} />

                    <InputForm id={'repetir-password-nuevo'} descripcion={'Repite la nueva contraseña'} tipo={'password'} modificador={setConfirmarPassword} valor={confirmarPassword} color={'text-black'} />

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
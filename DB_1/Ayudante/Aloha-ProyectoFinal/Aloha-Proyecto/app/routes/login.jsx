import { useEffect, useState } from "react";
import { Link, useOutletContext, useNavigate } from "@remix-run/react"

import InputForm from "../components/input-form"
import Alerta from "../components/alerta";

import axios from "axios";
import InputPassword from "~/components/input-password";

export default function Login() {

    const { auth, setAuth } = useOutletContext();
    const navigate = useNavigate();

    useEffect(() => {
        if (auth && auth.id_usuario) navigate("/perfil")
    }, [])

    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [alerta, setAlerta] = useState({});

    async function handleSubmit(e) {
        e.preventDefault();

        if ([email, password].includes('')) {
            setAlerta({
                msg: 'Todos los campos son obligatorios',
                error: true
            })
            return
        }

        try {
            const { data } = await axios.post(`http://localhost:5000/api/usuarios/login`, { email, password })

            const { token, usuario } = data;
            // const { id_usuario, nombre, apellido, email, telefono } = usuario;

            const objetoAuth = {
                id_usuario: usuario.id_usuario,
                nombre: usuario.nombre,
                apellido: usuario.apellido,
                email: usuario.email,
                telefono: usuario.telefono,
            }

            localStorage.setItem('token', token); // Guardamos el token en el localStorage
            localStorage.setItem('auth', JSON.stringify(objetoAuth)); // Guardamos el objetoAuth en el localStorage

            console.log(data);

            setAuth(objetoAuth); // Guardamos el objetoAuth en el contexto

            setAlerta({ // Mostramos la alerta
                msg: data.msg,
                error: false
            })

            navigate("/") // Redireccionamos al inicio si pasa la validación

        } catch (error) {
            setAlerta({
                msg: error.response.data.msg,
                error: true
            })
        }
    }

    const { msg } = alerta;

    return (
        <>
            <h1 className="text-3xl text-color-aloha text-center font-bold">Bienvenido</h1>
            <p className="text-black px-10 font-bold text-center mb-10">Recuerda que con tus compras acumulas puntos</p>

            {msg && (
                <div className='-mt-4'>
                    <Alerta alerta={alerta} />
                </div>
            )}

            <form onSubmit={handleSubmit}>
                <InputForm id={'username'} descripcion={'Email o Nombre de Usuario'} tipo={'text'} modificador={setEmail} valor={email} color={'text-black'} obligatorio={true} />

                <InputPassword id={'password'} descripcion={'Contraseña'} modificador={setPassword} valor={password} color={'text-black'} obligatorio={true} /> {/* PASSWORD */}

                <Link to={'/olvide-password'} className="flex justify-end text-color-aloha w-4/5 md:w-2/5 m-auto font-bold text-xs mt-2">He olvidado mi contraseña</Link>

                <div className="text-center my-7">
                    <input type="submit" value='Entrar' className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 m-auto font-bold" />
                </div>
            </form>

            <div className="font-bold flex gap-1 mt-5 justify-center text-sm">
                <p>No tengo cuenta</p>
                <Link to="/registro" className="text-color-aloha">crear cuenta </Link>
            </div>

        </>
    )
}

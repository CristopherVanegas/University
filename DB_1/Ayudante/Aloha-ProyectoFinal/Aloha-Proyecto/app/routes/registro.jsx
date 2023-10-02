import { useState, useEffect } from "react";
import { Link, useNavigate, useOutletContext, useLoaderData } from "@remix-run/react"

import axios from "axios"

import InputForm from "../components/input-form"
import Alerta from "../components/alerta";
import InputPassword from "~/components/input-password";

export default function Registro() {

    const [nombre, setNombre] = useState('')
    const [apellido, setApellido] = useState('')
    const [telefono, settelefono] = useState('')
    const [email, setEmail] = useState('');
    const [password, setPassword] = useState('');
    const [repetirPassword, setRepetirPassword] = useState('');

    const [alerta, setAlerta] = useState({})

    const { auth, setAuth } = useOutletContext();
    const navigate = useNavigate();

    useEffect(() => {
        if (auth && auth._id) navigate("/perfil")
    }, [])

    const handleSubmit = async e => {
        e.preventDefault();

        setAlerta({})

        if ([nombre, email, password, repetirPassword, apellido].includes('')) {
            setAlerta({
                msg: 'Los campos con * son obligatorios',
                error: true
            })
            return
        }

        if (telefono == "" || (Number(telefono) < 99999999 || Number(telefono) > 999999999)) {
            setAlerta({
                msg: 'Número de teléfono inválido',
                error: true
            })
            return
        }

        if (password !== repetirPassword) {
            setAlerta({
                msg: 'Los password no son iguales',
                error: true
            })
            return
        }

        if (password.length < 6) {
            setAlerta({
                msg: 'El password es muy corto, agrega mínimo 6 caracteres',
                error: true
            })
            return
        }

        //Crear el usuario en la API
        try {

            const requestData = { email, password, nombre, apellido };
            if (telefono) requestData.telefono = telefono;

            const { data } = await axios.post(`http://localhost:5000/api/usuarios/registrar`, requestData);
            const { token, usuario } = data;

            setAlerta({
                msg: data.msg,
                error: false
            })

            //Limpiando el formulario
            setNombre('');
            setEmail('');
            setPassword('');
            setRepetirPassword('');
            setApellido('');
            settelefono('');

            setTimeout(() => {
                navigate("/");
            }, 1800)

            const objetoAuth = {
                id_usuario: usuario[0].id_usuario,
                nombre: usuario[0].nombre,
                apellido: usuario[0].apellido,
                email: usuario[0].email,
                telefono: usuario[0].telefono,
            }

            localStorage.setItem('token', token); // Guardamos el token en el localStorage
            localStorage.setItem('auth', JSON.stringify(objetoAuth)); // Guardamos el objetoAuth en el localStorage

            console.log(data);

            setAuth(objetoAuth); // Guardamos el objetoAuth en el contexto

        } catch (error) {
            setAlerta({
                msg: error.response.data.msg,
                error: true
            })
        }

    }

    const { msg } = alerta

    return (
        <>
            <h1 className="text-3xl text-color-aloha text-center font-bold">Registro</h1>
            <p className="text-black px-10 font-bold text-center mb-10">Acumula puntos por tus compras</p>

            {msg && (
                <div className='-mt-4'>
                    <Alerta alerta={alerta} />
                </div>
            )}

            <form onSubmit={handleSubmit}>
                <InputForm id={'nombre'} descripcion={'Nombre'} tipo={'text'} modificador={setNombre} valor={nombre} color={'text-black'} obligatorio={true} /> {/* NOMBRE */}

                <InputForm id={'apellido'} descripcion={'Apellido'} tipo={'text'} modificador={setApellido} valor={apellido} color={'text-black'} obligatorio={true} /> {/* APELLIDO */}

                <InputForm id={'correo'} descripcion={'Correo Electrónico'} tipo={'email'} modificador={setEmail} valor={email} color={'text-black'} obligatorio={true} /> {/* EMAIL */}

                <InputForm id={'telefono'} descripcion={'Número de teléfono'} tipo={'number'} modificador={settelefono} valor={telefono} color={'text-black'} obligatorio={true} /> {/* telefono */}

                <InputPassword id={'password'} descripcion={'Contraseña'} modificador={setPassword} valor={password} color={'text-black'} obligatorio={true} /> {/* PASSWORD */}

                <InputPassword id={'repetir-password'} descripcion={'Repetir Contraseña'} modificador={setRepetirPassword} valor={repetirPassword} color={'text-black'} obligatorio={true} /> {/* RE-PASSWORD */}

                <div className="text-center mt-4 mb-2">
                    <input type="submit" value='REGISTRARME' className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja py-1 px-4 m-auto font-bold" />
                </div>
            </form>

            <div className="font-bold flex gap-1 mt-5 justify-center text-sm">
                <p>Ya tengo cuenta</p>
                <Link to={'/login'} className="text-color-aloha">{''}iniciar sesión</Link>
            </div>

        </>
    )
}

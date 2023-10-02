import { useState, useEffect } from "react"
import { useOutletContext, useNavigate } from "@remix-run/react";

import InputForm from "~/components/input-form"
import Alerta from "~/components/alerta";

import axios from "axios";

export default function TrabajaConNosotros() {

    const { auth } = useOutletContext();
    const navigate = useNavigate();

    useEffect(() => {
        if (auth.length === 0 || auth == undefined || auth == []) navigate("/login")
    }, [])

    const token = typeof window !== "undefined" && localStorage.getItem("token");

    const [email, setEmail] = useState(auth?.email || '');
    const [nombre, setNombre] = useState(auth?.nombre || '');
    const [apellido, setApellido] = useState(auth?.apellido || '');
    const [experiencia, setExperiencia] = useState(false);
    const [detalleExperiencia, setDetalleExperiencia] = useState('');
    const [alerta, setAlerta] = useState({});
    const [phone, setPhone] = useState(auth?.telefono || '');

    const handleSubmit = async e => {
        e.preventDefault();

        if ([email, nombre, apellido, experiencia].includes('')) {
            setAlerta({
                msg: 'Todos los campos son obligatorios',
                error: true
            })
            return
        }

        if([detalleExperiencia].includes('') && experiencia){
            setAlerta({
                msg: 'Ingrese su experiencia',
                error: true
            })
            return
        }

        if (phone == "" || (Number(phone) < 99999999 || Number(phone) > 999999999)) {
            setAlerta({
                msg: 'Número de teléfono inválido',
                error: true
            })
            return
        }

        if(experiencia && detalleExperiencia != "cocina" && detalleExperiencia != "mesero" && detalleExperiencia != "cajero" && detalleExperiencia != "todas"){
            setAlerta({
                msg: 'Ingrese una experiencia válida',
                error: true
            })
            return
        }

        const config = {
            headers: {
              "Content-Type": "application/json",
              Authorization: `Bearer ${token}`,
            },
          };

        try {
            const { data } = await axios.post(`http://localhost:5000/api/usuarios/trabaja-con-nosotros`, { email, experiencia, detalleExperiencia }, config)

            setAlerta({
                msg: data.msg,
                error: false
            })

            window.location.href = `mailto:talento@alohacafe.ec?subject=CV ${nombre} ${apellido}`;

        } catch (error) {
            setAlerta({
                msg: error.response.data.msg,
                error: true
            })
        }

    }

    const { msg } = alerta;

    return (
        <main>
            <h1 className="text-3xl text-color-aloha text-center font-bold">Trabaja Con Nosotros</h1>
            <p className="text-black px-10 font-bold text-center mb-10">Déjanos tus datos para contactarte</p>

            {msg && (
                <div className='-mt-4'>
                    <Alerta alerta={alerta} />
                </div>
            )}

            <form onSubmit={handleSubmit}>
                <InputForm id={'email'} descripcion={'Email'} tipo={'email'} valor={email} color={'text-black'} />

                <InputForm id={'nombre'} descripcion={'Nombre'} tipo={'text'} valor={nombre} color={'text-black'} />

                <InputForm id={'apellido'} descripcion={'Apellido'} tipo={'text'} valor={apellido} color={'text-black'} />

                <InputForm id={'phone'} descripcion={'Número Celular'} tipo={'number'} valor={phone} color={'text-black'} />

                <div>
                    <div className="m-auto space-y-2 w-4/5 md:w-2/5 mb-2">
                        <label htmlFor={`experiencia`} className="font-bold text-base">Experiencia En Restaurantes</label>
                    </div>

                    <div className="mt-2 flex justify-center">
                        <select
                            value={experiencia}
                            id={`experiencia`}
                            onChange={e => setExperiencia(e.target.value)}
                            className={"sombra-aloha rounded-xl w-4/5 md:w-2/5 h-12 bg-white flex justify-center text-center text-gray-aaa"}
                        >
                            <option value="">-- Seleccione --</option>
                            <option key={'No tengo experiencia'} value={false}>No tengo experiencia</option>
                            <option key={'Si tengo experiencia'} value={true}>Si tengo experiencia</option>
                        </select>
                    </div>


                    {experiencia && (
                        <div className="mt-2">
                            <div className="m-auto space-y-2 w-4/5 md:w-2/5 mb-2">
                                <label htmlFor={`experiencia`} className="font-bold text-base">En que campo tienes experiencia</label>
                            </div>
                            <div className="mt-2 flex justify-center">
                                <select
                                    value={detalleExperiencia}
                                    id={`detalle-experiencia`}
                                    onChange={e => setDetalleExperiencia(e.target.value)}
                                    className={"sombra-aloha rounded-xl w-4/5 md:w-2/5 h-12 bg-white flex justify-center text-center text-gray-aaa"}
                                >
                                    <option value="">-- Seleccione --</option>
                                    <option key={'Cocina'} value={'cocina'}>Cocinero/a</option>
                                    <option key={'Cajero'} value={'cajero'}>Cajero/a</option>
                                    <option key={'Mesero'} value={'mesero'}>Mesero/a</option>
                                    <option key={'Todas'} value={'todas'}>Todas las anteriores</option>
                                </select>
                            </div>
                        </div>
                    )}
                </div>

                <div className="text-center my-7">
                    <input type="submit" value={'Enviar Curriculum'} className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 m-auto font-bold" />
                </div>
            </form>
        </main>
    )
}

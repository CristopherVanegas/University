export default function InputPagar({icono, titulo, valor, modificador, opciones, id, obligatorio}) {

    return (
        <>
            <div className="flex justify-center items-center mt-3">
                <div className="mr-1">{ icono }</div>
                <div className="flex gap-1">
                    <p className="font-semibold text-lg">{titulo}</p>
                    { obligatorio && <p className="text-color-aloha font-bold">*</p>}
                </div>
            </div>

            <div className="flex justify-center">
                <div className="mt-2 flex justify-center sombra-aloha rounded-xl w-4/5 md:w-2/5 h-12 bg-white text-center text-gray-aaa">
                    <select
                        value={`${valor}`}
                        id={`${id}`}
                        onChange={e => modificador(e.target.value)}
                        className={"flex justify-center bg-transparent w-full text-center rounded-xl"}
                    >
                        <option value="">-- Seleccione --</option>
                        { opciones.map( opcion => (
                            <option key={opcion.value} value={opcion.value}>{opcion.titulo}</option>
                        )) }
                    </select>
                </div>
            </div>
        </>
    )
}

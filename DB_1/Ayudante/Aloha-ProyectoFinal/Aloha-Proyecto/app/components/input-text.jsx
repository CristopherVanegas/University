
export default function InputText({ icon, id, titulo, valor, modificador, placeholder, obligatorio }) {
    return (
        <>
            <div className="flex justify-center items-center mt-3">
                <div className="mr-2">{icon}</div>
                <div className="flex gap-1">
                    <p className="font-semibold text-lg">{titulo}</p>
                    { obligatorio && <p className="text-color-aloha font-bold">*</p>}
                </div>
            </div>

            <div className="mt-2">
                <div className="flex justify-center my-2">
                    <div className="sombra-aloha rounded-xl w-4/5 md:w-2/5 h-12 bg-white flex justify-center">
                        <input id={`${id}`} type={"text"} value={valor}
                            placeholder= {placeholder}
                            className={`h-11 px-3 w-full rounded-xl mt-0.5 bg-transparent text-black text-center`}
                            onChange={e => modificador(e.target.value)}
                        />
                    </div>
                </div>
            </div>
        </>
    )
}

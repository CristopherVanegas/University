import { useState } from "react"

export default function InputPassword({ descripcion, id, modificador, valor, color, obligatorio }) {

    const [verPassword, setVerPassword] = useState(true);

    const changeVisibilidadPassword = () => {
        setVerPassword(!verPassword);
    }

    return (
        <div className="m-auto w-4/5 md:w-2/5 mb-2">

            <div className="flex gap-1">
                <label htmlFor={`${id}`} className="font-bold text-base">{descripcion}</label>
                {obligatorio && <p className="text-color-aloha font-bold">*</p>}
            </div>

            {verPassword ? (
                <div className="relative ojito-distancia top-5" onClick={changeVisibilidadPassword}>
                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24">
                        <path fill="#e13028" d="M12 4.5C7 4.5 2.73 7.61 1 12c1.73 4.39 6 7.5 11 7.5s9.27-3.11 11-7.5c-1.73-4.39-6-7.5-11-7.5zM12 17c-2.76 0-5-2.24-5-5s2.24-5 5-5s5 2.24 5 5s-2.24 5-5 5zm0-8c-1.66 0-3 1.34-3 3s1.34 3 3 3s3-1.34 3-3s-1.34-3-3-3z" />
                    </svg>
                </div>
            ) : (
                <div className="relative ojito-distancia top-5" onClick={changeVisibilidadPassword}>
                    <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24">
                        <path fill="#e13028" d="M11.83 9L15 12.16V12a3 3 0 0 0-3-3h-.17m-4.3.8l1.55 1.55c-.05.21-.08.42-.08.65a3 3 0 0 0 3 3c.22 0 .44-.03.65-.08l1.55 1.55c-.67.33-1.41.53-2.2.53a5 5 0 0 1-5-5c0-.79.2-1.53.53-2.2M2 4.27l2.28 2.28l.45.45C3.08 8.3 1.78 10 1 12c1.73 4.39 6 7.5 11 7.5c1.55 0 3.03-.3 4.38-.84l.43.42L19.73 22L21 20.73L3.27 3M12 7a5 5 0 0 1 5 5c0 .64-.13 1.26-.36 1.82l2.93 2.93c1.5-1.25 2.7-2.89 3.43-4.75c-1.73-4.39-6-7.5-11-7.5c-1.4 0-2.74.25-4 .7l2.17 2.15C10.74 7.13 11.35 7 12 7Z" />
                    </svg>
                </div>
            )}

            <div className="sombra-aloha rounded-xl h-12 bg-white flex justify-center -mt-4">
                <input
                    id={`${id}`}
                    type={verPassword ? "password" : "text"}
                    className={`h-11 px-3 w-full rounded-xl mt-0.5 bg-transparent ${color}`}
                    value={valor}
                    onChange={e => modificador(e.target.value)}
                />
            </div>
        </div>
    )
}

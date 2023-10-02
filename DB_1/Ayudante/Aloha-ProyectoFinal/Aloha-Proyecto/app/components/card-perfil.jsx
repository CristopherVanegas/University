import { Link } from "@remix-run/react"

export default function CardPerfil({icono, titulo, enlace}) {
    return (
        <Link to={enlace} className="sombra-aloha rounded-xl w-5/6 justify-around bg-white flex-col py-2">
            { icono }
            <p className="mt-1.5 text-center text-gray-aaa font-medium text-xs">{titulo}</p>
        </Link>
    )
}

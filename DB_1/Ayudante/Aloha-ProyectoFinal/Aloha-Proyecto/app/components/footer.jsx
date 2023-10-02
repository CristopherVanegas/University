import { Link, useLocation } from "@remix-run/react"

export default function Footer({cantidadProductosCarrito}) {

  const token = typeof window !== "undefined" && localStorage.getItem("token");

  const location = useLocation();
  const color = location.pathname.startsWith("/perfil")

  return (
    <footer className="flex justify-center items-center w-full mt-20">
      <div className="flex justify-around items-center sombra-aloha w-4/5 lg:w-2/5 lg:h-15 p-3 fixed bottom-4 bg-white rounded-xl z-40">

        <Link to={ token ? "/perfil" : "/login"} alt='Login'>
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill={location.pathname == "/login" ? "#E13028" : location.pathname == "/registro" ? "#E13028" : color ? "#E13028" : "#aaa"} className="w-6 lg:w-8 h-6 lg:h-8">
            <path fillRule="evenodd" d="M7.5 6a4.5 4.5 0 119 0 4.5 4.5 0 01-9 0zM3.751 20.105a8.25 8.25 0 0116.498 0 .75.75 0 01-.437.695A18.683 18.683 0 0112 22.5c-2.786 0-5.433-.608-7.812-1.7a.75.75 0 01-.437-.695z" clipRule="evenodd" />
          </svg>
        </Link>

        <Link to="/" alt='Inicio'>
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill={location.pathname == "/" ? "#E13028" : "#aaa"} className="w-6 lg:w-8 h-6 lg:h-8">
            <path d="M11.47 3.84a.75.75 0 011.06 0l8.69 8.69a.75.75 0 101.06-1.06l-8.689-8.69a2.25 2.25 0 00-3.182 0l-8.69 8.69a.75.75 0 001.061 1.06l8.69-8.69z" />
            <path d="M12 5.432l8.159 8.159c.03.03.06.058.091.086v6.198c0 1.035-.84 1.875-1.875 1.875H15a.75.75 0 01-.75-.75v-4.5a.75.75 0 00-.75-.75h-3a.75.75 0 00-.75.75V21a.75.75 0 01-.75.75H5.625a1.875 1.875 0 01-1.875-1.875v-6.198a2.29 2.29 0 00.091-.086L12 5.43z" />
          </svg>
        </Link>

        <Link to="/carrito" alt='Carrito'>
          <svg xmlns="http://www.w3.org/2000/svg" className="w-6 lg:w-8 h-6 lg:h-8" viewBox="0 0 256 256">
            <path fill={location.pathname == "/carrito" ? "#E13028" : "#aaa"} d="m223.9 65.4l-12.2 66.9a24 24 0 0 1-23.6 19.7h-116l4.4 24H184a24 24 0 1 1-24 24a23.6 23.6 0 0 1 1.4-8h-58.8a23.6 23.6 0 0 1 1.4 8a24 24 0 1 1-42.2-15.6L34.1 32H16a8 8 0 0 1 0-16h18.1a16 16 0 0 1 15.7 13.1L54.7 56H216a7.9 7.9 0 0 1 6.1 2.9a7.7 7.7 0 0 1 1.8 6.5Z" />

            <circle cx="175" cy="80" r={"80"} fill="#E13028" />
            <text x={"175"} y={"120"} fontSize={"110"} fontWeight="bold" fill="white" textAnchor="middle">{cantidadProductosCarrito}</text>
          </svg>
        </Link>
      </div>
    </footer>
  )
}


import { useLocation } from '@remix-run/react';
import { Link } from 'react-router-dom'
import LogoAloha from '../../public/img/LogoAloha.svg'

import { useState } from 'react';
// import Busqueda from './Busqueda';

// import { HamburguerMenuIcon } from 'svg/iconos';
// import NavbarOpciones from './navbar-opciones';
// import Menu from './menu';

export default function Header({ productos }) {

  const [buscador, setBuscador] = useState(false);
  const [menu, setMenu] = useState(false);

  const [visibleLogo, setVisibleLogo] = useState(true);

  const location = useLocation();
  const isHomePage = location.pathname === "/";

  const handleBuscador = () => {
    setBuscador(!buscador)
  }

  const handleMenu = () => {
    setMenu(!menu)
  }

  const handleLinkClick = () => {
    setMenu(false);
  };

  return (
    <div className='mb-20 md:mb-28'>
    <header className='fixed top-0 left-0 w-full bg-white z-40'>
      <div className='flex justify-between items-center'>

          <Link to={'/'} className={`logo-aloha m-3 z-20 ${visibleLogo ? "" : "invisible"}`}>
            <img src={LogoAloha} alt="Logo Aloha" className='logo-aloha' />
          </Link>

        <div>

          <div className='flex'>
            <div className='flex m-5 space-x-2 lg:space-x-4 items-center'>
              <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="#E13028" className="w-7 h-7" onClick={() => { handleBuscador() }}>
                <path fillRule="evenodd" d="M10.5 3.75a6.75 6.75 0 100 13.5 6.75 6.75 0 000-13.5zM2.25 10.5a8.25 8.25 0 1114.59 5.28l4.69 4.69a.75.75 0 11-1.06 1.06l-4.69-4.69A8.25 8.25 0 012.25 10.5z" clipRule="evenodd" />
              </svg>

              <div className={'md:hidden'} onClick={() => { 
                handleMenu();
                setVisibleLogo(false);
              }}>
                {/* <HamburguerMenuIcon /> */}
              </div>

              {/* {menu && <Menu setMenu={setMenu} setVisibleLogo={setVisibleLogo}/>} */}

              <nav className='barra-navegacion xs:hidden sm:hidden md:block space-x-4 flex items-center font-bold sm:text-lg lg:text-xl uppercase outline-none'>
                <Link to={"/perfil"} className={`${location.pathname == "/perfil" ? "text-color-aloha" : ""} xs:ml-4`} onClick={handleLinkClick}>Mi Perfil</Link>
                {/* <Link to={"/perfil/mis-pedidos"} className={`${location.pathname == "/mis-pedidos" ? "text-color-aloha" : ""}`} onClick={handleLinkClick}>Mis Pedidos</Link>
                <Link to={"/perfil/mis-puntos"} className={`${location.pathname == "/mis-puntos" ? "text-color-aloha" : ""}`} onClick={handleLinkClick}>Mis Puntos</Link> */}
                <Link to={"/trabaja-con-nosotros"} className={`${location.pathname == "/trabaja-con-nosotros" ? "text-color-aloha" : ""}`} onClick={handleLinkClick}>Trabaja Con Nosotros</Link>
              </nav>

            </div>

          </div>

          {/* <Busqueda buscador={buscador} handleBuscador={handleBuscador} productos={productos} /> */}

        </div>
      </div>

      {/* {isHomePage && <NavbarOpciones />} */}
    </header>
    </div>
  )
}

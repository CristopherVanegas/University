import { useState, useEffect } from "react";

import Header from "./components/header";
import Footer from "./components/footer";

import stylesheet from "~/tailwind.css"

import disponibilidadHorario from "helpers/disponibilidadHorario";

import {
  Links,
  LiveReload,
  Meta,
  Outlet,
  Scripts,
  ScrollRestoration,
  useLoaderData,
} from "@remix-run/react";

import { obtenerProductos } from "../models/productos.server"; // importar la función obtenerProductos del archivo productos.server.js

export const links = () => [
  {
    rel: "stylesheet",
    href: stylesheet
  }
];

export async function loader({ request, params }) {
  const productos = await obtenerProductos();

  return { productos };
}

export default function App() {

  const authLS = typeof window !== 'undefined' ? JSON.parse(localStorage.getItem('auth')) ?? [] : null
  const [auth, setAuth] = useState(authLS); // Estado de la autenticación

  const carritoLS = typeof window !== 'undefined' ? JSON.parse(localStorage.getItem('carrito')) ?? [] : null
  const [carrito, setCarrito] = useState(carritoLS) // Estado del carrito

  const pedidoLS = typeof window !== 'undefined' ? JSON.parse(localStorage.getItem('pedido')) ?? [] : null
  const [pedido, setPedido] = useState(pedidoLS);

  const [cantidadProductosCarrito, setCantidadProductosCarrito] = useState(0);

  const [disponibilidad, setDisponibilidad] = useState({});

  const { productos } = useLoaderData(); // Obtener los productos del loader

  useEffect(() => {
    localStorage.setItem('carrito', JSON.stringify(carrito))
    if (carrito[0] && carrito[0].nombre && carrito[0].cantidad === 0) {
      setCarrito([]);
    }

    let cantidadProductos = 0;
    carrito.forEach(producto => {
      cantidadProductos += producto.cantidad;
    });

    setCantidadProductosCarrito(cantidadProductos);

  }, [carrito])

  // Funciones para el carrito

  const agregarCarrito = (producto) => {

    if (carrito.some(productoState => productoState.id_producto === producto.id_producto)) { //Bool: Existe duplicado

      const carritoActualizado = carrito.map(productoState => {  //Iterar e identificar el elemento duplicado
        if (productoState.id_producto === producto.id_producto) productoState.cantidad = producto.cantidad //Remplazar solo la cantidad
        return productoState
      })

      setCarrito(carritoActualizado)
    }

    else setCarrito([...carrito, producto]) //Registro nuevo - agregar al carrito
  }

  const actualizarCarrito = producto => {
    const carritoActualizado = carrito.map(productoState => {
      if (productoState.id_producto === producto.id_producto) {
        productoState.cantidad = producto.cantidad

        productos.find(productoStateTwo => {
          productoStateTwo.id_producto == productoState.id_producto ?
            productoStateTwo.cantidad = producto.cantidad : ""
        })
      }
      return productoState
    })
    setCarrito(carritoActualizado)
  }

  const eliminarProducto = id => {
    const carritoActualizado = carrito.filter(productoState => {
      if (productoState.id_producto !== id)
        return productoState
    })
    setCarrito(carritoActualizado)
  }

  // Funciones para la disponibilidad de horario
  useEffect(() => {
    const verDiponibilidad = disponibilidadHorario();
    setDisponibilidad(verDiponibilidad)
  }, []);

  // Funciones para el pedido
  useEffect(() => {
    localStorage.setItem('pedido', JSON.stringify(pedido))
    if (!pedido && (pedido.entrega == undefined || pedido.entrega == null)) {
      setPedido({});
    }
  }, [pedido])

  return (
    <html lang="en">
      <head>
        <meta charSet="utf-8" />
        <meta name="viewport" content="width=device-width,initial-scale=1" />
        <Meta />
        <Links />
      </head>
      <body>
        <Header />
        <Outlet
          context={{
            auth,
            setAuth,
            productos,
            carrito,
            setCarrito,
            agregarCarrito,
            actualizarCarrito,
            eliminarProducto,
            disponibilidad,
            setDisponibilidad,
            pedido,
            setPedido
          }}
        />
        <Footer cantidadProductosCarrito={cantidadProductosCarrito} />
        <ScrollRestoration />
        <Scripts />
        <LiveReload />
      </body>
    </html>
  );
}

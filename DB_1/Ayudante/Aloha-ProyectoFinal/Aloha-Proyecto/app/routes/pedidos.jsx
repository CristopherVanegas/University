import { useState } from "react"
import useSWR from "swr"
import axios from "axios"
import Orden from "~/components/orden";

function Pedidos() {
  const [pedidos, setPedidos] = useState([]);

  const token = typeof window !== "undefined" && localStorage.getItem("token");

  const config = {
    headers: {
      "Content-Type": "application/json",
      Authorization: `Bearer ${token}`,
    },
  };

  const fetcher = () => axios('http://localhost:5000/api/ordenes', config).then(datos => datos.data);

  useSWR("http://localhost:5000/api/ordenes", () => { fetcher().then(pedidos => { setPedidos(pedidos) }) }, { refreshInterval: 5000 });

  const hoy = new Date().toLocaleDateString('es-MX', { weekday: 'long', year: 'numeric', month: 'long', day: 'numeric' }); // Obtener la fecha actual en formato largo

  return (
    <main>
      <h1 className="text-3xl text-color-aloha text-center font-bold capitalize">{hoy}</h1>
      {pedidos.length ? pedidos.map(orden => (
        <Orden
          key={orden._id}
          orden={orden}
        />
      )) : (
        <p className="text-black px-10 font-bold text-center mb-10">No hay Ordenes</p>
      )}
    </main>
  )
}

export default Pedidos;

import axios from "axios";

export default function Orden({ orden }) {

    const { id_orden: id, estado, productos, valor_total, nombre_sucursal: localComercial, nombre_usuario: cliente } = orden;

    const token = typeof window !== "undefined" && localStorage.getItem("token");

    const config = {
      headers: {
        "Content-Type": "application/json",
        Authorization: `Bearer ${token}`,
      },
    };

    const completarOrden = async (estado) => {
        const confirmar = window.confirm(`¿Seguro que quieres marcar esta orden como ${estado}?`);
        if (!confirmar) return;

        const data = { estado }

        try {
            await axios.post(`http://localhost:5000/api/ordenes/cambiar-estado/${id}`, data, config);
        } catch (error) {
            return "Hubo un error"
        }
    }

    return (
        <div className="xs:flex xs:flex-col grid grid-cols-2 gap-4 mx-4">
            <div className={`${estado == "Completado" || estado == "Llegue" ? "md:col-start-2 bg-green-300" : "bg-blue-300"} w-full p-3 rounded-md mt-4`}>
                <h2 className="text-lg font-bold uppercase">Orden #{id}</h2>

                <div className="flex mt-3 gap-1 text-lg">
                    <h3>Cliente:</h3>
                    <p className="font-bold">{cliente}</p>
                </div>

                <div className="flex mt-3 gap-1 text-lg">
                    <h3>Estado:</h3>
                    <p className="font-bold">{estado}</p>
                </div>

                <h3 className="font-bold mt-3">Productos:</h3>

                <ul>
                    {productos?.map(producto => (
                        <li key={id}>{producto.cantidad} {producto.nombre}</li>
                    ))}
                </ul>

                <div className="flex mt-3 gap-1 text-lg">
                    <h4 className="font-bold">Total a Pagar:</h4>
                    <p>${valor_total}</p>
                </div>

                <p className="text-lg font-bold mt-4">{ "Local: " + localComercial}</p>

                <div className={`xs:flex xs:justify-between xs:mt-4 flex justify-end text-white rounded-md gap-2 ${estado == "Completado" ? "hidden" : ""}`}>

                    <button onClick={() => completarOrden("Preparando")} className={`bg-blue-600 hover:bg-blue-700 text-white font-bold py-2 px-2 rounded inline-block ${estado == "Preparando" ? "hidden" : ""}`}>Preparando</button>

                    <button onClick={() => completarOrden("Completado")} className={`bg-blue-600 hover:bg-blue-700 text-white font-bold py-2 px-2 rounded inline-block`}>Completada</button>
                </div>
            </div>

        </div>
    )
}

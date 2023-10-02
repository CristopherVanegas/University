import ManejadorCantidades from "./manejador-cantidades";

export default function CardProductoCarrito({ producto }) {

    const { nombre, cantidad, precio, imagen } = producto;

    return (
        <main className="md:m-auto">
            <div className="flex mt-8 md:justify-center items-center">
                <img src={`${imagen}`} alt={nombre} className={`margin-producto w-2/4 h-auto object-contain md:w-1/6 ${nombre.startsWith("Promo") ? "p-7" : ""}`} style={{ borderRadius: "3rem"}} />

                <div>
                    <h2 className='text-black font-bold text-lg'>{nombre}</h2>

                    <div className="mt-2 mb-6">
                        <ManejadorCantidades producto={producto} />
                    </div>

                    <p className="font-bold text-color-aloha mt-4">${precio}</p>

                    <div className="flex items-center mt-1">
                        <p className="text-base font-normal mr-1">Subtotal</p>
                        <p className="font-bold text-lg">${precio * cantidad}</p>
                    </div>

                </div>
            </div>

            <hr className="w-4/5 md:w-1/4 bg-gray-700 m-auto mt-3 mb-10" />
        </main>
    )
}

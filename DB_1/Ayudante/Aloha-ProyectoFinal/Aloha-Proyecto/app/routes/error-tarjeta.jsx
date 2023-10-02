import { Link } from "@remix-run/react";

export default function Error() {
    return (
        <main className="main-ups">
            <h1 className="text-3xl md:text-4xl lg:text-5xl text-color-aloha text-center font-bold">Ups...</h1>

            <div className="flex text-black font-bold text-center mt-3 justify-center items-center">
                <p className="text-lg md:text-2xl lg:text-4xl px-4">Ha ocurrido un error al procesar tu tarjeta
                    <span className="text-2xl md:text-4xl lg:text-6xl">🥹</span>
                    , revisa que tengas los fondos suficientes o que no este caducada porfavor y reintenta el pago, o usa otra tarjeta
                </p>
            </div>

            <div className="flex justify-center my-8">
                <Link to='/' className="text-white uppercase text-xl md:text-2xl lg:text-4xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 font-bold text-center ">Volver al Inicio</Link>
            </div>
        </main>
    )
}

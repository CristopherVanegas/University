import Costos from "./costos"

export default function ResumenPagar({ subtotal, total, setTotal, entrega }) {

    let envio = 0;
    const tarifas = Number(subtotal) * 0.10;

    if (entrega === "Delivery") {
        envio = 2.5;
    }
    else {
        envio = 0;
    }

    setTotal(envio + tarifas + subtotal)

    return (
        <div className="mt-5">
            <div className="w-4/5 md:w-2/5 m-auto">

                <Costos titulo={'Subototal'} valor={subtotal.toFixed(2)} />
                <Costos titulo={'Envío'} valor={envio.toFixed(2)} />
                <Costos titulo={'Tarifas'} valor={tarifas.toFixed(2)} />

                <div className="flex justify-between text-lg font-bold">
                    <p>Total</p>
                    <p>USD {`${total.toFixed(2)}`}</p>
                </div>

            </div>

            {entrega == "Delivery" ? (
                <div className="text-center my-7">
                    <input type="submit" value='HACER PEDIDO' className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 m-auto font-bold" disabled={entrega === "Delivery" && envio == 0 ? true : false} />
                </div>
            ) : (
                <div className="text-center mt-7 mb-7">
                    <input type="submit" value='HACER PEDIDO' className="text-white uppercase text-xl bg-color-aloha rounded-lg sombra-aloha-roja px-4 py-1 m-auto font-bold" />
                </div>
            )}

        </div>
    )
}

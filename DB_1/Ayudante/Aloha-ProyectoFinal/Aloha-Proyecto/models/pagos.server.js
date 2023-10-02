import axios from "axios";

export async function prepararPago(dataUserPayment) {

    console.log(dataUserPayment);

    const { amount, amountWithoutTax, clientTransactionID, responseUrl, cancellationUrl } = dataUserPayment;

    const response = await fetch(`${process.env.API_URL}/productos/pagar`, {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({ amount, amountWithoutTax, clientTransactionID, responseUrl, cancellationUrl })
    })

    return await response.json();
}

export async function fetchPayohone(transaccion, clientTransactionId) {
    try {
        const { data } = await axios(`${process.env.API_URL}/productos/respuesta-pago/${transaccion}&${clientTransactionId}`);

        return await data;
    } catch (error) {
        console.error(error);
    }
}

export async function crearOrden(pedido, token) {
    try {
        const config = {
            headers: {
                "Content-Type": "application/json",
                Authorization: `Bearer ${token}`,
            },
        };

        const { data } = await axios.post(`http://localhost:5000/api/ordenes/crear-orden`, pedido, config);
        return await data;
    } catch (error) {
        console.log(error);
    }
}

export async function obtenerOrden(id_orden, token) {
    try {
        const config = {
            headers: {
                "Content-Type": "application/json",
                Authorization: `Bearer ${token}`,
            },
        };

        const { data } = await axios(`http://localhost:5000/api/ordenes/${id_orden}`, config);
        return await data;

    } catch (error) {
        console.log(error);
    }
}
const validarCampos = (entrega, metodoPago, localComercial, position, descripcion, factura, clienteFactura, cedula, numero) => {
    const errores = [];

    if (!entrega) {
        errores.push("Selecciona una opción de entrega");
    }

    if (!metodoPago) {
        errores.push("Selecciona un método de pago");
    }

    if (entrega === "Local" && !localComercial) {
        errores.push("Debe seleccionar el local");
    }

    return errores;
};

export default validarCampos;
function disponibilidadHorario(localComercial='') {

    const today = new Date().getDay();
    const hours = 12;
    let respuesta = { disponibilidad: true, mensaje: '' };

    // No Disponible - Madrugada de 0 a      6 AM o más de las 19 horas en fin de semana y 20 horas dias normales
    if ((hours >= 0 && hours <= 6) || ((today === 6 || today === 0) && hours > 19) || (today !== 6 && today !== 0 && hours > 20)) {
        respuesta = { disponibilidad: false, mensaje: 'Aloha Café está cerrado en este momento y solo acepta pedidos durante el horario de atención.' };
    }

    else if (today === 6 || today === 0) { // Sábados y Domingos
        if ((localComercial !== 'Ceibos' && localComercial !== "") && hours > 13) {
            respuesta = { disponibilidad: false, mensaje: `Aloha Café ${localComercial} esta cerrado en este momento, y solo acepta pedidos de Ceibos` };
        }
    }

    else {
        if ((localComercial !== 'Ceibos' && localComercial !== "") && hours > 14) {
            respuesta = { disponibilidad: false, mensaje: `Aloha Café ${localComercial} esta cerrado en este momento, y solo acepta pedidos de Ceibos` };
        }
    }

    return respuesta;
}

export default disponibilidadHorario;
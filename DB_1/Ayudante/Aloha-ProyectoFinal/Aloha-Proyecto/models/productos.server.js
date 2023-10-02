export async function obtenerProductos() {
    const respuesta = await fetch(`http://localhost:5000/api/productos`)
    return await respuesta.json()
}

export async function obtenerProducto(producto) {
    const respuesta = await fetch(`${process.env.API_URL}/productos/${producto}`)
    return await respuesta.json()
}
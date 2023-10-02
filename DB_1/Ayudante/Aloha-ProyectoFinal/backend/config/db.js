import pkg from 'pg';
const { Client } = pkg;

const conectarDB = async (queryRaw) => {
    
    // Conexión a la base de datos con pg y variables de entorno
    const client = new Client({
        user: process.env.DB_USER,
        host: process.env.DB_HOST,
        database: process.env.DB_DATABASE,
        password: process.env.DB_PASSWORD,
        port: process.env.DB_PORT
    });

    try {
        await client.connect() // Conexión a la base de datos

        const respuesta = await client.query(queryRaw); // Ejecutar la consulta      
        return respuesta.rows; // Retornar el resultado de la consulta

    } catch (error) {
        console.log(error);    
    }

    await client.end()
}

export default conectarDB;
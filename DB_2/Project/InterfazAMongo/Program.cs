/*                    PROYECTO BASE DE DATOS 2                    */
/*                    [] INTERFAZ POR CONSOLA                     */
/*                           INTEGRANTES                          */
/*                     >  CRISTIAN ALAÑA                          */
/*                     >  ANDREA PRIETO                           */
/*                     >  ANDY BAJAÑA                             */
/*                     >  CRISTOPHER VANEGAS                      */

using System;
using System.Collections.Generic;
using MongoDB.Driver;
using MongoDB.Bson;
using MongoDB.Bson.Serialization;
using System.Net.WebSockets;
using Amazon.Runtime.SharedInterfaces;
using System.Text.Json;

class Usuario
{
    public string username { get; set; }
    public string password { get; set; }
    public string fechaCreacion { get; set; }
}

class Objeto
{
    public string id { get; set; }
    public string nombre { get; set; }
    public string fechaIngreso { get; set; }
    public string ownerUsername { get; set; }
    public string ownerPassword { get; set; }
}

class Sistema
{
    // Instanciar MongoDB y referenciar la base de datos y colecciones pertinentes
    static MongoClient client = new MongoClient("mongodb://localhost:27017");
    static IMongoDatabase database = client.GetDatabase("Inventario");
    static IMongoCollection<Usuario> usuarios = database.GetCollection<Usuario>("Usuarios");
    static IMongoCollection<Objeto> objetos = database.GetCollection<Objeto>("Objetos");

    // Lista donde se van a almacenar los usuarios registrados
    static public List<Usuario> listaUsuarios = new List<Usuario>();
    
    // Lista donde se van a almacenar los objetos guardados
    static public List<Objeto> listaObjetos = new List<Objeto>();

    
    



    static public void IngresarObjeto(string sesionUsername, string sesionPassword)
    {
        // Se ingresa el nombre del objeto
        string nombre;
        do
        {
            Console.WriteLine("Ingrese el nombre del objeto que desea guardar (3-20 caracteres):");
            nombre = Console.ReadLine();
            if (nombre.Length < 3 || nombre.Length > 20)
            {
                Console.WriteLine("\nEl nombre del objeto debe tener entre 3 y 20 caracteres. Inténtelo nuevamente\n");
            }
        } while (nombre.Length < 3 || nombre.Length > 20);

        // Se genera un código hexadecimal aleatorio de 6 dígitos para que actúe como clave primaria o ID del objeto
        Random random = new Random();
        byte[] buffer = new byte[3];
        random.NextBytes(buffer);
        string id = BitConverter.ToString(buffer).Replace("-", string.Empty);

        // Fecha y hora ingreso exactos
        DateTime fechaAhora = DateTime.Now;
        string fechaIngreso = fechaAhora.ToString("yyyy-MM-dd HH:mm:ss");

        // Crea instancia para ingresar un nuevo objeto
        Objeto nuevoObjeto = new Objeto();
        nuevoObjeto.id = id;
        nuevoObjeto.nombre = nombre;
        nuevoObjeto.fechaIngreso = fechaIngreso;
        nuevoObjeto.ownerUsername = sesionUsername;
        nuevoObjeto.ownerPassword = sesionPassword;
        listaObjetos.Add(nuevoObjeto);

        // Referenciamos la colección y agregamos el objeto
        var coleccionObjetos = database.GetCollection<Objeto>("Objetos");
        coleccionObjetos.InsertOne(nuevoObjeto);

        Console.WriteLine($"\nSe ha ingresado el objeto {nombre} bajo el nombre de usuario {sesionUsername}. El código de su objeto es {id}.\n");
    }

    static public void RetirarObjeto(string sesionUsername, string sesionPassword)
    {
        // Se ingresa el código del objeto
        Console.WriteLine("Ingrese el código del objeto que desea retirar:");
        string id = Console.ReadLine();

        // Se busca el objeto con el código ingresado en consola dentro de la lista
        Objeto buscaObjeto = listaObjetos.Find(objeto => objeto.id == id);

        // Código ingresado no pertenece a ningún objeto
        if (buscaObjeto == null)
        {
            Console.WriteLine($"\nNo se encontró ningún objeto con el código {id}.\n");
            return;
        }
        else
        {
            // Código pertenece a un objeto, pero de un diferente usuario
            if (buscaObjeto.ownerUsername != sesionUsername)
            {
                Console.WriteLine("\nEste objeto pertenece a un usuario diferente.\n");
                return;
            }
            else
            {
                // Verificación de identidad del usuario antes de retirar el objeto
                Console.WriteLine($"\nCompruebe su identidad antes de continuar. Ingrese la contraseña para el usuario {sesionUsername}");
                string verificacion = Console.ReadLine();

                // Verificación fallida
                if (verificacion != sesionPassword)
                {
                    Console.WriteLine("\nLa contraseña ingresada es incorrecta. Inténtelo nuevamente.\n");
                    return;
                }
                else
                {
                    // Retiro de pertenencia exitoso
                    listaObjetos.Remove(buscaObjeto);


                    // Acceso a la colección "usuarios"
                    var collection = database.GetCollection<BsonDocument>("Objetos");

                    // Creación del filtro
                    var filter = Builders<BsonDocument>.Filter.Eq("_id", id);

                    // Eliminación del documento
                    var result = collection.DeleteOne(filter);

                    // Impresión del resultado
                    Console.WriteLine($"Número de items eliminados: {result.DeletedCount}");


                    Console.WriteLine($"\nSe ha retirado el objeto con el código {id} del inventario.\n");
                }
            }
        }
    }

    static public void VerInventario()
    {
        int x = 0; int y = 4;
        Console.WriteLine("Estos son todos los objetos que se encuentran guardados en el inventario:\n");
        Console.WriteLine("ID           OBJETO                     FECHA INGRESO             DUEÑO");
        Console.WriteLine("——           ——————                     —————————————             —————");

        foreach (Objeto objeto in listaObjetos)
        {
            Console.SetCursorPosition(x, y);
            Console.WriteLine(objeto.id);
            Console.SetCursorPosition(x + 13, y);
            Console.WriteLine(objeto.nombre);
            Console.SetCursorPosition(x + 40, y);
            Console.WriteLine(objeto.fechaIngreso);
            Console.SetCursorPosition(x + 66, y);
            Console.WriteLine(objeto.ownerUsername);
            y++;
        }
        Console.WriteLine("\n");
    }

    // Método para el registro de usuarios
    static public void RegistrarCuenta()
    {
        string username; string password;
        do
        {
            Console.WriteLine("Ingrese su nombre de usuario deseado (3-20 caracteres):");
            username = Console.ReadLine();
            if (username.Length < 3 || username.Length > 20)
            {
                Console.WriteLine("\nEl nombre de usuario debe tener entre 3 y 20 caracteres. Inténtelo nuevamente\n");
            }
        } while (username.Length < 3 || username.Length > 20);

        do
        {
            Console.WriteLine("\nIngrese su contraseña deseada (3-20 caracteres):");
            password = Console.ReadLine();
            if (password.Length < 3 || password.Length > 20)
            {
                Console.WriteLine("\nLa contraseña debe tener entre 3 y 20 caracteres. Inténtelo nuevamente\n");
            }
        } while (password.Length < 3 || password.Length > 20);

        DateTime fechaAhora = DateTime.Now;
        string fechaCreacion = fechaAhora.ToString("yyyy-MM-dd HH:mm:ss");

        // Verificación de datos
        if (listaUsuarios.Any(u => u.username == username))
        {
            Console.WriteLine("\nYa existe una cuenta con este nombre de usuario. Inténtelo nuevamente.\n");
            return;
        }

        // Creación de usuario
        Usuario nuevoUsuario = new Usuario();
        nuevoUsuario.username = username;
        nuevoUsuario.password = password;
        nuevoUsuario.fechaCreacion = fechaCreacion;
        listaUsuarios.Add(nuevoUsuario);

        // Referenciamos colección y agregamos objeto
        var coleccionUsuarios = database.GetCollection<Usuario>("Usuarios");
        coleccionUsuarios.InsertOne(nuevoUsuario);

        Console.WriteLine("\n¡Cuenta registrada con éxito!\n");
    }

    // Método para inicio de sesión de usuarios
    static public void IniciarSesion()
    {
        Console.WriteLine("Ingrese su nombre de usuario:");
        string username = Console.ReadLine();

        Console.WriteLine("\nIngrese su contraseña:");
        string password = Console.ReadLine();

        // Verificación de datos incorrectos o no existentes
        Usuario usuario = listaUsuarios.FirstOrDefault(u => u.username == username);

        if (usuario == null)
        {
            Console.WriteLine("\nNo existe una cuenta con este nombre de usuario. Inténtelo nuevamente.\n");
            return;
        }

        if (usuario.password != password)
        {
            Console.WriteLine("\nLa contraseña ingresada es incorrecta. Inténtelo nuevamente.\n");
            return;
        }

        // Campos en donde se guarda los datos de la sesión actual
        string sesionUsername = username;
        string sesionPassword = password;
        bool sesion = true;

        Console.WriteLine("\n¡Inicio de sesión exitoso!\n");

        // Una vez el inicio de sesión es exitoso, aparece un nuevo menú:
        while (sesion == true)
        {
            Console.WriteLine($"¡Saludos, {sesionUsername}!");
            Console.WriteLine("A continuación, seleccione una acción a realizar:");
            Console.WriteLine("1. Ingresar objeto");
            Console.WriteLine("2. Retirar objeto");
            Console.WriteLine("3. Ver inventario");
            Console.WriteLine("4. Cerrar sesión\n");

            int opcion = int.Parse(Console.ReadLine());
            Console.Clear();

            switch (opcion)
            {
                case 1:
                    Sistema.IngresarObjeto(sesionUsername, sesionPassword);
                    break;
                case 2:
                    Sistema.RetirarObjeto(sesionUsername, sesionPassword);
                    break;
                case 3:
                    Sistema.VerInventario();
                    break;
                case 4:
                    sesion = false;
                    Console.WriteLine($"Has cerrado sesión bajo el usuario {sesionUsername}.");
                    break;
                default:
                    Console.WriteLine("\nOpción inválida.\n");
                    break;
            }
        }
    }

    static public void VerUsuarios()
    {
        int x = 0; int y = 4;
        Console.WriteLine("Estos son todos los usuarios que se han registrado en el sistema:\n");
        Console.WriteLine("USUARIO                   FECHA CREACIÓN           CONTRASEÑA");
        Console.WriteLine("———————                   ——————————————           ——————————");

        foreach (Usuario usuario in listaUsuarios)
        {
            Console.SetCursorPosition(x, y);
            Console.WriteLine(usuario.username);
            Console.SetCursorPosition(x + 26, y);
            Console.WriteLine(usuario.fechaCreacion);
            Console.SetCursorPosition(x + 51, y);
            Console.WriteLine(usuario.password);
            y++;
        }
        Console.WriteLine("\n");
    }

    static void Main(string[] args)
    {
        while (true)
        {
            Console.WriteLine("Menú de inventario universitario");
            Console.WriteLine("A continuación, seleccione una acción a realizar:");
            Console.WriteLine("1. Registrar cuenta");
            Console.WriteLine("2. Iniciar sesión");
            Console.WriteLine("3. Ver usuarios");
            Console.WriteLine("4. Salir\n");

            int opcion = int.Parse(Console.ReadLine());
            Console.Clear();

            switch (opcion)
            {
                case 1:
                    Sistema.RegistrarCuenta();
                    break;
                case 2:
                    Sistema.IniciarSesion();
                    break;
                case 3:
                    Sistema.VerUsuarios();
                    break;
                case 4:
                    Environment.Exit(0);
                    break;
                default:
                    Console.WriteLine("\nOpción inválida\n");
                    break;
            }
        }
    }
}

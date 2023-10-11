/*8.Desarrolle un algoritmo que simule el ingreso de una clave numérica para entrar a un sistema con un intento de ingreso de tres veces, en el último intento sale del sistema.
Nota: Envíe mensajes de Ingreso al Sistema o Salió del sistema por ingreso incorrecto de contraseña.*/

using System;

public class ingresoAlSistema
{
    static void Main(string[] args)
    {
        string passwrd = "";

        for (; ; )
        {
            Console.Clear();
            Console.Write("Ingrese una contraseña: ");
            passwrd = Console.ReadLine();

            Console.Write("Confirme la contraseña: ");
            if (passwrd == Console.ReadLine())
            {
                break;
            }
            else
            {
                Console.WriteLine("Las claves no coinciden!");
                Thread.Sleep(1000);
            }
        }

        int attemps = 0;

        for (; ; )
        {
            Console.Clear();s
            if (attemps == 3)
            {
                Console.WriteLine("Intentos máximos, ingreso no permitido!");
                Environment.Exit(0);
            }
            else
            {
                Console.Write("Ingrese la contraseña para iniciar sesion, intento de inicio número {0} maximo 3: ", attemps + 1);
                if (Console.ReadLine() == passwrd)
                {
                    Console.WriteLine("Inicio de sesion exitoso!");
                    Environment.Exit(0);
                }
                else
                {
                    Console.WriteLine("Contraseña incorrecta!");
                    ++attemps;
                }
            }
        }
    }
}
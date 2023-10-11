// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

namespace Program009
{
    public class Program
    {
        static int[] miArray = new int[10];

        static void Main(string[] args)
        {
            IngresarNumeros();
            MostrarDatos();

            do
            {
                Existe();
                CuantosSonIguales();
                Console.Write("\n\nDesea buscar otro numero (any / n) ? ");
            } while (Console.ReadKey().KeyChar != 'n');
        }

        static void IngresarNumeros()
        {
            for (int i = 0; i < miArray.Length; i++)
            {
                Console.Clear();
                int n;
                do
                {
                    Console.Write("Ingrese un numero para la posicion {0}: ", i);
                    n = Convert.ToInt32(Console.ReadLine());

                } while (n == 0);
                miArray[i] = n;
            }
        }

        static void MostrarDatos()
        {
            for (int i = 0; i < miArray.Length; i++)
            {
                Console.WriteLine(" [Posicion: {0}] {1}", i, miArray[i]);
            }
        }

        static void Existe()
        {
            int n;
            do
            {
                Console.Write("\nIngrese un numero para para buscar: ");
                n = Convert.ToInt32(Console.ReadLine());

            } while (n == 0);

            for (int i = 0; i < miArray.Length; i++)
            {
                if (n == miArray[i])
                {
                    Console.WriteLine("Existe: {0}", true);
                    return;
                }
            }
            Console.WriteLine("Existe: {0}", false);
        }

        static void CuantosSonIguales()
        {
            int n, c = 0;
            do
            {
                Console.Write("\nIngrese un numero para para buscar: ");
                n = Convert.ToInt32(Console.ReadLine());

            } while (n == 0);

            for (int i = 0; i < miArray.Length; i++)
            {
                if (n == miArray[i])
                {
                    Console.WriteLine("Se encontro en la posicion {0}", i);
                    c++;
                }
            }

            Console.WriteLine("Hay {0} repetidos", c);
        }
    }
}
using System;

namespace Program011
{
    public class Program
    {
        static int[] myArr = new int[15];
        static void Main(String[] args)
        {
            IngresarDatos(myArr);
            BuscarPosicion(myArr);
        }
        static void IngresarDatos(int[] myArr)
        {
            for (int i = 0; i < myArr.Length; i++)
            {
                Console.Write(" [ console ] Ingrese un valor para la posicion {0}: ", i);
                myArr[i] = Convert.ToInt32(Console.ReadLine());
            }
        }

        static void BuscarPosicion(int[] arr)
        {
            int n, c = 0;
            do
            {
                Console.Write("\nIngrese un numero para para buscar: ");
                n = Convert.ToInt32(Console.ReadLine());

            } while (n == 0);

            for (int i = 0; i < arr.Length; i++)
            {
                if (n == arr[i])
                {
                    Console.WriteLine("Se encontró en la posicion {0}", i);
                    c++;
                }
            }

            Console.WriteLine("Hay {0} repetidos", c);
        }
    }
}



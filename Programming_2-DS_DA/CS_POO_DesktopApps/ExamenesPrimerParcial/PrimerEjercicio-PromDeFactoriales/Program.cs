
using System;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;

class Program
{
    static void Main(string[] args)
    {
        int[] arr = new int[10];
        
        // pido numeros
        for (int i = 0; i < arr.Length; i++)
        {
            Console.Write("Ingrese un numero para la posicion {0}: ", i);
            arr[i] = Convert.ToInt32(Console.ReadLine());
            Console.Clear();
        }

        Console.WriteLine("El promedio de factoriales de todos los numeros ingresados es: {0}", getPromedioFactoriales(arr));

    }
    static double getPromedioFactoriales(int[] arr)
    {
        int ac = 0;

        // Itero mi array de numeros
        for (int i = 0; i < arr.Length; i++)
        {
            ac += getFactorial(arr[i]);
        }

        double prom = ac / arr.Length;
        

        return prom;
    }

    static int getFactorial(int n)
    {
        int factN = 1;

        // Saco factorial de cada numero
        for (int j = n; j > 0; j--)
        {
            factN *= j;
        }

        return factN;
    }
}
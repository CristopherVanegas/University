/* 3.Ingresar por teclado una secuencia de números hasta que se ingrese el cero. Luego,
Determinar cuántos de estos números fueron positivos y negativos.
Nota: El cero puede ser contado como positivo. */


using System;

public class secuenciaDeNumeros
{
    public static void Main(string[] args)
    {
        int[] arr = new int[255];
        int c = 0;

        for (; ; )
        {
            Console.Clear();
            Console.Write("Ingrese un numero, ingrese 0 para parar: ");
            int n = Convert.ToInt32(Console.ReadLine());
            arr[c] = n;
            ++c;

            if (n == 0) break;
        }

        int posN = 0, negN = 0;

        for (int i = 0; i < c; i++)
        {
            if (arr[i] >= 0) posN++;
            else negN++;
        }

        for (int i = 0; i < c; i++) Console.Write(" > {0} ", arr[i]);

        Console.WriteLine("");
        Console.WriteLine("Numeros positivos {0}", posN);
        Console.WriteLine("Numeros negativos {0}", negN);
    }
}




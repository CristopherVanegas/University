/*5.Leer un número hasta que este se encuentre entre los valores 1 y 10 incluidos. Si un número
Si el número ingresado no está en ese rango el programa pide el ingreso de otro número.*/

using System;

public class rango1A10
{
    static void Main(string[] args)
    {

        int[] arr = new int[255];
        int c = 0;

        for(; ; )
        {
            Console.Clear();
            Console.Write("Ingrese un numero: ");
            arr[c] = Convert.ToInt32(Console.ReadLine());

            c++;
            if (arr[c-1] > 0 && arr[c-1] <= 10) break;
        }

        Console.WriteLine("");
        Console.WriteLine("c: {0}", c);
        for (int i = 0; i < c; i++) Console.Write(" > {0}", arr[i]);
        Console.WriteLine("");
    }
}

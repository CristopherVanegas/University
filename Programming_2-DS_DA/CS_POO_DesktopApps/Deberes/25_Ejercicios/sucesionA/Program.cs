/*23.Construya un algoritmo que calcule la suma de los primeros n términos de las series siguientes (el n debe ser ingresado como parámetro a la función)*/

using System;

public class sucesionA{
    static void Main(string[] args)
    {
        Console.WriteLine("Sucesion A");
        Console.Write("Ingrese un numero para la sucesion: ");
        int n = Convert.ToInt32(Console.ReadLine());
        double a = 0;

        for (int i = 1; i <= n; i++)
        {
            a += (Math.Pow(-1, (i + 1)) / ((3 * n) + 1));
        }
        Console.WriteLine("El resultado es: {0}", a);
    }
}

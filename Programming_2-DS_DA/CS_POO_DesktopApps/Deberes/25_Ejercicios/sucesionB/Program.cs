/*23.Construya un algoritmo que calcule la suma de los primeros n términos de las series siguientes (el n debe ser ingresado como parámetro a la función)*/

using System;

public class sucesionB
{
    static void Main(string[] args)
    {
        Console.WriteLine("Sucesion B");
        Console.Write("Ingrese un numero para la sucesion: ");
        int n = Convert.ToInt32(Console.ReadLine());
        double a = 0;

        for (int i = 1; i <= n; i++)
        {
            a += (Math.Cos(i)/Math.Pow(i, 2));
        }
        Console.WriteLine("El resultado es: {0}", a);
    }
}

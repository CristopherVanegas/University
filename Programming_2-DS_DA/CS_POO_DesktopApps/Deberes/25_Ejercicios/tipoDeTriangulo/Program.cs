/*25.Dados tres lados de entrada S1, S2 y S3 determinar qué tipo de triángulo forman ellos, considerando que si: */

using System;
using System.Drawing;

public class tipoDeTriangulos
{
    static void Main(string[] args)
    {
        Console.Write("Ingrese el S1: ");
        int S1 = Convert.ToInt32(Console.ReadLine());

        Console.Write("Ingrese el S2: ");
        int S2 = Convert.ToInt32(Console.ReadLine());

        Console.Write("Ingrese el S3: ");
        int S3 = Convert.ToInt32(Console.ReadLine());

        if ((S1 + S2) > S3 || (S1 + S3) > S2 || (S2 + S3) > S1)
        {
            if (S1 == S2 && S2 == S3) Console.WriteLine("El triángulo es equilatero");
            else if (S1 != S2 && S2 != S3) Console.WriteLine("El triángulo es escaleno");
            else if (S1 == S2 || S1 == S3 || S2 == S3) Console.WriteLine("El triángulo es isósceles");
        }
        else Console.WriteLine("No es un triángulo");

    }
}

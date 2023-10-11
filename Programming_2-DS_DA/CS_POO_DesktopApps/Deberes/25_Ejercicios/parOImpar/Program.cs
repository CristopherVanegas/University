/*6. Determinar si un número de tipo entero de entrada es par o impar.*/

using System;

public class parOImpar
{
    static void Main(string[] args)
    {
        Console.Write("Ingrese un numero: ");
        int n = Convert.ToInt32(Console.ReadLine());

        if (n % 2 == 0) Console.WriteLine("{0} es par. ", n);
        else Console.WriteLine("{0} es impar.", n);
    }
}

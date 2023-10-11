// 2.Encontrar e imprimir el número mayor de dos elementos de entrada.

using System;

public class numeroMayor
{
    public static void Main(string[] args)
    {
        Console.Write("Ingrese primer numero ");
        int n1 = Convert.ToInt32(Console.ReadLine());

        Console.Write("Ingrese segundo numero ");
        int n2 = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("");

        if (n1 > n2) Console.WriteLine("{0} es mayor", n1);
        else Console.WriteLine("{0} es mayor", n2);


    }
}

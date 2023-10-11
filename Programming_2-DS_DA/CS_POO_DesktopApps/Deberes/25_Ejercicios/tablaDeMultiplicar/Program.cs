using System;

public class tablaDeMultiplicar
{
    public static void Main(string[] args)
    {
        Console.Write("Ingrese la tabla de multiplicar que desea: ");
        int num = Convert.ToInt32(Console.ReadLine());

        Console.Write("Ingrese hasta que numero desea la tabla: ");
        int n = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("");

        for (int i = 1; i <= n; i++)
        {
            Console.WriteLine("{0} * {1} es: {2}", num, n, num*i);
        }


    }
}
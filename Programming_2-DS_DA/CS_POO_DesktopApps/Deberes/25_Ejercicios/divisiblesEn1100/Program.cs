/*19.Determinar e imprimir la cantidad de números divisibles por N entre el intervalo [1,1000]*/

using System;

public class divisiblesEnUnRango
{
    static void Main(string[] args)
    {
        Console.Write("Ingrese el número divisor: ");
        int n = Convert.ToInt32(Console.ReadLine());
        int c = 0;
        
        for (int i = 1; i <= 1100; i++)
        {
            if (i % n == 0)
            {
                Console.Write(" > {0} ", i);
                ++c;
            }
        }

        Console.WriteLine("\nNúmeros divisibles {0}", c);
    }
}
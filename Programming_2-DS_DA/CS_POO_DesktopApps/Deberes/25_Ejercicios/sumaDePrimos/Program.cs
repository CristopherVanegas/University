/*24.Construya un algoritmo que permita obtener la SUMA de los primeros 20 términos de la serie:
X = 1 + 3 + 5 + 7 + ...*/

using System;

public class sumaDePrimos {
    static void Main(string[] args)
    {
        int acum = 1;
        for (int i = 0; i < 20; i++)
        {
            Console.Write(" > {0} ", acum);
            acum = acum + 2;
        }

        Console.WriteLine("\nSuma total: {0}", ((20 / 2) * (1 + 39)));
    }
}

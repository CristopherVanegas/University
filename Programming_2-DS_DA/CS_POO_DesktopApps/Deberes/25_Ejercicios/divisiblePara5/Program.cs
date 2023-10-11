/* 4.Si un número X entero ingresado por el usuario es divisible por 5. El programa debe 
Imprimir uno de los dos siguientes mensajes:
X es divisible por 5
X no es divisible por 5. */


using System;

public class divisiblePara5
{
    public static void Main(string[] args)
    {
        Console.Write("Ingrese un numero: ");
        int n = Convert.ToInt32(Console.ReadLine());

        if (n % 5 == 0) Console.WriteLine("{0} es divisible para 5.", n);
        else Console.WriteLine("{0} no es divisible para 5", n);
    }
}




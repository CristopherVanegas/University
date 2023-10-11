/*20.Leer dos números de entrada y determinar el cociente y el resto de la división entre ambos utilizando solo sumas y restas. E imprimir valores finales.*/

using System;

public class CocienteYRestoSinDivision
{
    static void Main(string[] args)
    {
        Console.Write("Ingrese el dividendo: ");
        int dividendo = Convert.ToInt32(Console.ReadLine());

        Console.Write("Ingrese el divisor: ");
        int divisor = Convert.ToInt32(Console.ReadLine());

        int residuo = dividendo;
        int cociente = 0;

        while (residuo >= divisor)
        {
            residuo -= divisor;
            cociente++;
        }

        Console.WriteLine("El cociente es {0} y el residuo es de {1}", cociente, residuo);
    }
}

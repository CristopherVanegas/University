/*7.Determinar el número mayor y el menor de n números de entrada y entregar la diferencia entre ellos sin utilización de resta.*/

class diferenciaSinResta
{
    static void Main(string[] args)
    {
        Console.Write("Ingrese primer numero: ");
        int n1 = Convert.ToInt32(Console.ReadLine());

        Console.Write("Ingrese segundo numero: ");
        int n2 = Convert.ToInt32(Console.ReadLine());

        if (n1 > n2) Console.WriteLine("{0} es mayor", n1);
        else Console.WriteLine("{0} es mayor", n2);

        double sqrt1 = Math.Sqrt(n1);
        double sqrt2 = Math.Sqrt(n2);

        Console.WriteLine("La diferencia es {0}", Convert.ToInt32((Math.Pow(sqrt1, 2) - Math.Pow(sqrt2, 2))));
    }
}
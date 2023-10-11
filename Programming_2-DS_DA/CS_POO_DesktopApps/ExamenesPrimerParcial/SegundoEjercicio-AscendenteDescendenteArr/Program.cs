
using System;

class Program
{
    static void Main(string[] args)
    {
        Console.Write("Ingrese la dimension de su arreglo: ");
        int s = Convert.ToInt32(Console.ReadLine());

        int[] arr = new int[s];

        Random random = new Random();

        // inicializo el array
        for (int i = 0; i < arr.Length; i++)
        {
            arr[i] = random.Next(1250);
        }

        Ordenamiento(arr);
    }
    static void Ordenamiento(int[] arr)
    {
        Console.Write("Desea ordenar ascendente o descendente? (1 / 0): ");
        int o = Convert.ToInt32(Console.ReadLine());

        switch (o)
        {
            case 0:
                {
                    Ascendente(arr);
                } break;
            case 1:
                {
                    Descendente(arr);
                } break;
        }
    }
    static void mostrar(int[] arr, string s)
    {
        if (s == "Ascendente") Console.Write("Ascendente: ");
        else if (s == "Descendente") Console.Write("Descendente: ");

        for (int i = 0;i < arr.Length;i++)
        {
            Console.Write("{0} ", arr[i]);
        }
        Console.WriteLine();
    }

    static void Ascendente(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            int aux = 0;

            for (int j = i + 1; j < arr.Length; j++)
            {
                if (arr[j] < arr[i])
                {
                    aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
        }

        mostrar(arr, "Ascendente");
    }
    static void Descendente(int[] arr)
    {
        for (int i = 0; i < arr.Length; i++)
        {
            int aux = 0;

            for (int j = i + 1; j < arr.Length; j++)
            {
                if (arr[j] > arr[i])
                {
                    aux = arr[i];
                    arr[i] = arr[j];
                    arr[j] = aux;
                }
            }
        }

        mostrar(arr, "Descendente");
    }
}

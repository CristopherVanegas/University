using System;

class Program
{
    static void Main()
    {
        float[] miArray = new float[10];

        for (int i = 0; i < miArray.Length; i++)
        {
            //            double n = (Console.ReadLine()) float;
            Console.Write("Ingrese un numero para la posicion {0}: ", i + 1);
            float.TryParse(Console.ReadLine(), out miArray[i]); // intenta hacer un parseo o conversion de la entrada string a float y lo guarda como salida en la posicion del array que se encuentre el iterador.
        }


        // los demas bucles son para iterar y a partir del condicional contar cuantos hay de cada seccion o sea menos o mayor a un determinado rango de nota.
        int c = 0;
        for (int i = 0; i < miArray.Length; i++)
        {
            if (miArray[i] >= 9 && miArray[i] <= 10) c++;
        }

        Console.WriteLine("Hay {0} numeros >= 9 y <= 10", c);

        c = 0;
        for (int i = 0; i < miArray.Length; i++)
        {
            if (miArray[i] >= 8 && miArray[i] < 9) c++;
        }

        Console.WriteLine("Hay {0} numeros >= 8 y < 9", c);

        c = 0;
        for (int i = 0; i < miArray.Length; i++)
        {
            if (miArray[i] >= 7 && miArray[i] < 8) c++;
        }

        Console.WriteLine("Hay {0} numeros >= 7 y < 8", c);
        
        c = 0;
        for (int i = 0; i < miArray.Length; i++)
        {
            if (miArray[i] >= 6 && miArray[i] < 7) c++;
        }

        Console.WriteLine("Hay {0} numeros >= 6 y < 7", c);

        c = 0;
        for (int i = 0; i < miArray.Length; i++)
        {
            if (miArray[i] < 6) c++;
        }

        Console.WriteLine("Hay {0} numeros < 6", c);

    }
}

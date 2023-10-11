// Online C# Editor for free
// Write, Edit and Run your C# code using C# Online Compiler

using System;

namespace Program010
{
    public class Program
    {
        static int[] arr = new int[15];

        static void Main(string[] args)
        {
            int answer = 0;
            do
            {
                answer = Menu();
            } while (answer != 0);
        }

        static int Menu()
        {
            Console.Clear();
            Console.WriteLine(" [ option 1 ] Ingresar");
            Console.WriteLine(" [ option 2 ] Consultar");
            Console.WriteLine(" [ option 3 ] Modificar");
            Console.WriteLine(" [ option 4 ] Eliminar");
            Console.WriteLine(" [ option 5 ] Salir");
            Console.Write(" [ answer ] >>> ");

            int opt = Convert.ToInt32(Console.ReadLine());
            switch (opt)
            {
                case 1:
                    {
                        IngresarDatos(arr);
                    } break;
                case 2:
                    {
                        Consultar(arr);
                    }
                    break;
                case 3:
                    {
                        Modificar(arr);
                    }
                    break;
                case 4:
                    {
                        Eliminar(arr);
                    }
                    break;
                case 5:
                    {
                        // salir //
                        return 0;
                    }
            }
            Continuar();
            return 1;
        }
        static void Continuar()
        {
            Console.WriteLine("\n\nPress Anykey to continue...");
            Console.ReadLine();
        }

        static void IngresarDatos(int[] myArr)
        {
            for (int i = 0; i < myArr.Length; i++)
            {
                Console.Write(" [ console ] Ingrese un valor para la posicion {0}: ", i);
                myArr[i] = Convert.ToInt32(Console.ReadLine());
            }
        }
        static void Consultar(int[] myArr)
        {
            Console.WriteLine(" [ console ] Desea buscar:");
            Console.WriteLine("             [ 1 ] Todos los elementos");
            Console.WriteLine("             [ 2 ] Uno en especifico");
            Console.Write(" [ answer ] >>> ");

            int opt = Convert.ToInt32(Console.ReadLine());

            switch (opt)
            {
                case 1:
                    {
                        for (int i = 0; i < myArr.Length; i++)
                        {
                            Console.WriteLine(" [ Position {0} ]: {1} ", i, myArr[i]);
                        }
                    } break;
                case 2:
                    {
                        Console.Write("\n [ console ] Ingrese el valor que busca: ");
                        int n = Convert.ToInt32(Console.ReadLine());

                        for (int i = 0; i < myArr.Length; i++)
                        {
                            if (myArr[i] == n) Console.WriteLine(" [ Position {0} ]: {1}", i, myArr[i]);
                        }
                    }   break;
            }
        }
        static void Modificar(int[] arr)
        {
            Console.Write(" [ console ] Que posicion desea modificar de 0 a {0}? ", arr.Length - 1);
            int pos = Convert.ToInt32(Console.ReadLine());

            Console.Write(" [ console ] Ingrese el nuevo valor: ");
            int num = Convert.ToInt32(Console.ReadLine());

            arr[pos] = num;

            Console.WriteLine(" [ console ] Listo! Puede consultar los datos actualizados!");
        }
        static void Eliminar(int[] arr)
        {
            Console.WriteLine(" [ console ] Desea eliminar:");
            Console.WriteLine("             [ 1 ] Todos los elementos");
            Console.WriteLine("             [ 2 ] Uno en especifico");
            Console.Write(" [ answer ] >>> ");

            int opt = Convert.ToInt32(Console.ReadLine());

            switch (opt)
            {
                case 1:
                    {
                        for (int i = 0; i < arr.Length; i++)
                        {
                            arr[i] = 0;
                        }
                        Console.WriteLine(" [ console ] Listo! Si desea puede consultar ahora los datos actualizados!");
                    }
                    break;
                case 2:
                    {
                        Console.Write("\n [ console ] Ingrese la posicion que desea eliminar de 0 a {0}: ", arr.Length - 1);
                        int pos = Convert.ToInt32(Console.ReadLine());

                        arr[pos] = 0;

                        if (pos < arr.Length - 1)
                        {
                            for (int i = pos; i < arr.Length - 1; i++)
                            {
                                int aux = arr[i];
                                arr[i] = arr[i + 1];
                                arr[i + 1] = aux;
                            }
                        }
                        Console.WriteLine(" [ console ] Listo! Puede ahora consultar los datos actualizados!");
                    }
                    break;
            }
        }
    }
}

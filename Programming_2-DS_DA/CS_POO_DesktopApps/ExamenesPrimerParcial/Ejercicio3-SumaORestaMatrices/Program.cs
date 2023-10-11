
using System;
using System.Diagnostics.CodeAnalysis;

class Program
{
    static void Main(string[] args)
    {


        Console.Write("Ingrese la dimension de su matrix... FILAS: ");
        int f = Convert.ToInt32(Console.ReadLine());
        Console.Write("Ingrese la dimension de su matrix... COLUM: ");
        int c = Convert.ToInt32(Console.ReadLine());

        int[,] matrixA = new int[f, c];
        int[,] matrixB = new int[f, c];

        Random random = new Random();

        // inicializo el array
        for (int i = 0; i < f; i++)
        {
            for (int j = 0; j < c; j++)
            {
                matrixA[i, j] = random.Next(10);
                matrixB[i, j] = random.Next(10);
            }
        }

        Console.WriteLine("Matrix A");
        MostrarMatriz(matrixA);

        Console.WriteLine("Matrix B");
        MostrarMatriz(matrixB);


        Console.Write("Desea sumar o restar? (0 / 1): ");
        int o = Convert.ToInt32(Console.ReadLine());

        Console.WriteLine("Matrix Resultado");
        MostrarMatriz(getResultado(matrixA, matrixB, o));
    }

    static void MostrarMatriz(int[,] matriz)
    {
        int filas = matriz.GetLength(0);
        int columnas = matriz.GetLength(1);

        for (int i = 0; i < filas; i++)
        {
            for (int j = 0; j < columnas; j++)
            {
                Console.Write(matriz[i, j] + "\t");
            }
            Console.WriteLine();
        }
    }

    static int[,] getResultado(int[,] matrix1, int[,] matrix2, int o)
    {

        int[,] result = new int[matrix1.GetLength(0), matrix1.GetLength(1)];

        switch (o)
        {
            case 0:
                {
                    // suma
                    for (int i = 0; i < matrix1.GetLength(0); i++)
                    {
                        for (int j = 0; j < matrix1.GetLength(1); j++)
                        {
                            result[i, j] = matrix1[i, j] + matrix2[i, j];
                        }
                    }

                } break;
            case 1:
                {
                    // resta
                    for (int i = 0; i < matrix1.GetLength(0); i++)
                    {
                        for (int j = 0; j < matrix1.GetLength(1); j++)
                        {
                            result[i, j] = matrix1[i, j] - matrix2[i, j];
                        }
                    }
                }
                break;
        }

        return result;
    }
}

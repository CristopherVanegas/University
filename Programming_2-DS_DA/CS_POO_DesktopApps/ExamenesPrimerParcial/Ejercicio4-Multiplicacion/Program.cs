
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

        Console.WriteLine("Matrix Resultado = MatrixA x MatrixB");
        MostrarMatriz(getMultiplicacion(matrixA, matrixB));
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

    static int[,] getMultiplicacion(int[,] matrix1, int[,] matrix2)
    {
        int Filas = matrix1.GetLength(0);
        int Columnas = matrix2.GetLength(1);

        int[,] result = new int[Filas, Columnas];

        if (matrix1.GetLength(1) != matrix2.GetLength(0))
        {
            throw new ArgumentException("Las matrices no se pueden multiplicar. El número de columnas de la matriz1 debe ser igual al número de filas de la matriz2.");
        }


        for (int i = 0; i < Filas; i++)
        {
            for (int j = 0; j < Columnas; j++)
            {
                int suma = 0;
                for (int k = 0; k < matrix1.GetLength(1); k++)
                {
                    suma += matrix1[i, k] * matrix2[k, j];
                }
                result[i, j] = suma;
            }
        }

        return result;
    }
}

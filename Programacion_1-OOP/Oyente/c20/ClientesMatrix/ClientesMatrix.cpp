// ClientesMatrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

const int row = 8, col = 12;

array<array<int, col>, row> clientes;
array<array<int, col>, row> ventas;


//	Function Declaration
void llenarTabla(char mode, array<array<int, col>, row>& matriz);
void mostrarTabla(const array<array<int, col>, row>& matriz, const string& titulo);
void mejorCliente(array<array<int, col>, row>& matriz, int rows, int cols);

int main()
{    
    std::cout << "Hello World!\n";
	llenarTabla('c', clientes);
	llenarTabla('v', ventas);
	mostrarTabla(clientes, "Tabla de Clientes | Col = Clientes & Fila Suc");
	mostrarTabla(ventas, "Tabla de Ventas | Col = Clientes & Fila Suc");
    mejorCliente(clientes, row, col);
}

void mejorCliente(array<array<int, col>, row>&matriz, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int n1 = 0;
        int c1 = 0;

        int n2 = matriz[i][0];
        int c2 = 1;

        for (int j = 0; j < cols; j++) {
            for (int jj = j+1; jj < cols; jj++) {
                ((matriz[i][j]) == matriz[i][jj]) ? (c2++) : NULL;
            }
        }
        /*
        if (c2 == c1) {
            cout << setw(5) << "En Sucursal " << i + 1 << " empate, los clientes que más compraron fueron: " << n1 << " y " << n2 << endl;
        }
        else if (c2 > c1) {
            n1 = n2;
            c1 = c2;
            cout << setw(5) << "En Sucursal " << i + 1 << " el cliente que mas compro fue : " << n1 << endl;
        }
        */

        cout << setw(5) << "En Sucursal " << i + 1 << " el cliente que mas compro fue : " << n1 << endl;
        
    }
}

void llenarTabla(char mode, array<array<int, col>, row>&matriz) {
	random_device rd;	// semilla para el random
	mt19937 gen(rd());	// creo un objeto para generar numeros aleatorios utilizando el Algoritmo MT

	switch (mode)
	{
		case 'c': {
			uniform_int_distribution<int> dist(0, 9);	// Setteo un rango de 0 a 9

			for (int i = 0; i < row; ++i)
				for (int j = 0; j < col; j++)
					matriz[i][j] = dist(gen);
		} break;

		case 'v': {
			uniform_int_distribution<int> dist(100, 550);	// Setteo un rango de 0 a 9

			for (int i = 0; i < row; ++i)
				for (int j = 0; j < col; j++)
					matriz[i][j] = dist(gen);
		} break;
	}
}

void mostrarTabla(const array<array<int, col>, row>&matriz, const string & titulo) {
    // Encontrar el número más grande en la matriz
    int maxNum = matriz[0][0];
    for (const auto& fila : matriz) {
        for (const auto& elemento : fila) {
            if (elemento > maxNum) {
                maxNum = elemento;
            }
        }
    }

    // Calcular el ancho necesario para los elementos de la matriz
    int ancho = to_string(maxNum).length() + 2;

    // Mostrar etiquetas de columnas
    cout << setw(ancho) << " ";
    for (int j = 0; j < col; ++j) {
        cout << "C" << j + 1 << setw(ancho);
    }
    cout << endl;

    // Mostrar la tabla sin etiquetas de filas
    for (int i = 0; i < row; ++i) {
        cout << setw(ancho) << " ";
        for (int j = 0; j < col; ++j) {
            cout << setw(ancho) << matriz[i][j] << " ";
        }
        cout << setw(3) << "S" << i + 1 << endl;
    }

    // Mostrar espacio en blanco para las etiquetas de columna
    cout << setw(ancho) << " ";
    for (int j = 0; j < col; ++j) {
        cout << setw(ancho) << " ";
    }
    cout << endl;
}

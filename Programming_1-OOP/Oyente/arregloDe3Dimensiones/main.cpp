#include <iostream>
#include <time.h>
#include "Herramienta.cpp"

using namespace std;



Ventas matriz[6][5][12];
Ventas objVentas;
string arregloCliente[] = { "hugo","paco",
							"luis","jose",
						    "maria","gustavo",
							"rosi","ernesto",
							"sofia","alejandra"};

string arregloProductos[10];
int arregloTemporal[10] = { 0 };
int i = 0;
int indice;

void inicializaArreglo(int varArreglo[10])
{
	for (int i = 0; i < 10; i++)
	{
		varArreglo[i] = 0;
	}

}

int indiceProducto(string varProducto)
{
	for (int i = 0; i < 10; i++)
	{
		if(varProducto == arregloProductos[i])
		{
			return i;
		}
	}
}

int mayor(int varArreglo[10])
{
	int mayor = varArreglo[0];
	for (int i = 0; i < 10; i++)
	{
		if (mayor < varArreglo[i])
		{
			mayor = varArreglo[i];
		}
	}
	return mayor;
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < 10; i++)
	{
		arregloProductos[i] = "Producto" + to_string(i);
	}

	for (int ciudad = 0; ciudad < 6; ciudad++)
	{
		for (int sucursal = 0; sucursal < 5; sucursal++)
		{
			for (int mes = 0; mes < 12; mes++)
			{
				matriz[ciudad][sucursal][mes].setCliente(arregloCliente[rand()%10]);
				matriz[ciudad][sucursal][mes].setProducto(arregloProductos[rand() % 10]);
				matriz[ciudad][sucursal][mes].setVenta(100 + rand() % 600);
			}
		}
	}



	for (int ciudad = 0; ciudad < 6; ciudad++)
	{
		for (int sucursal = 0; sucursal < 5; sucursal++)
		{
			for (int mes = 0; mes < 12; mes++)
			{
				cout<<matriz[ciudad][sucursal][mes].getCliente()<<"         "
				    <<matriz[ciudad][sucursal][mes].getProducto()<<"         "
					<<matriz[ciudad][sucursal][mes].getVenta()<<endl;
			}
			cout << endl << endl;
		}
	}

	//Producto que mas se vende por ciudad




	for (int ciudad = 0; ciudad < 1; ciudad++)
	{
		for (int sucursal = 0; sucursal < 2; sucursal++)
		{
			inicializaArreglo(arregloTemporal);

			for (int mes = 0; mes < 12; mes++)
			{
				indice= indiceProducto(matriz[ciudad][sucursal][mes].getProducto());
				arregloTemporal[indice] = arregloTemporal[indice] + matriz[ciudad][sucursal][mes].getVenta();

			}
			for (int i = 0; i < 10; i++)
			{
				cout << arregloTemporal[i] << " ";
			}
			cout << "el mayor es " << mayor(arregloTemporal) << endl;


		}
	}



}

#include <string>
#include <iostream>
using namespace std;

class Ventas
{
    private:
        string cliente;
        string producto;
        int venta;
public:
    void setCliente(string valor) { cliente = valor; }

    string getCliente() { return cliente; }

    void setProducto(string valor) { producto = valor; }

    string getProducto() { return producto; }

    void setVenta(int valor) { venta = valor; }

    int getVenta() { return venta; }



};

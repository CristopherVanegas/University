#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

using namespace std;

struct Product
{
    string description;
    int cant;
    int precio;

};

int id = 0;

struct Factura
{
    string name;
    int ID;
    string date[3]; // d, m, y
    Product detalleProductos[10];
    int total;
};

Factura facturas[255];

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

int menu()
{
    int opt;
    do
    {
        gotoxy(5, 0);
        cout << "Welcome to sales check CRUD!" << endl;
        gotoxy(5, 1);
        cout << "Please select an option" << endl;
        gotoxy(5, 2);
        cout << " [1]    Create a sales check!" << endl;
        gotoxy(5, 3);
        cout << " [2]    Create a massive" << endl;
        gotoxy(5, 4);
        cout << " [3]    Show data" << endl;
        gotoxy(5, 5);
        cout << " [4]    Search" << endl;
        gotoxy(5, 6);
        cout << " [5]    Upgrade" << endl;
        gotoxy(5, 7);
        cout << " [6]    Delete" << endl;
        gotoxy(5, 8);
        cout << " [7]    Save" << endl;
        gotoxy(5, 9);
        cout << " [8]    Best client!" << endl;
        gotoxy(5, 10);
        cout << " [9]    Higher product!" << endl;
        gotoxy(5, 11);
        cout << " [10]   Month that sold the most!" << endl;
        gotoxy(5, 12);
        cout << " [11]   Graph of sales chart" << endl;

        cin >> opt;
    }
    while (opt <= 0 || opt >= 11);

    gotoxy(5, 0);
    cout << "                                       " << endl;
    gotoxy(5, 1);
    cout << "                                       " << endl;
    gotoxy(5, 2);
    cout << "                                       " << endl;
    gotoxy(5, 3);
    cout << "                                       " << endl;
    gotoxy(5, 4);
    cout << "                                       " << endl;
    gotoxy(5, 5);
    cout << "                                       " << endl;
    gotoxy(5, 6);
    cout << "                                       " << endl;
    gotoxy(5, 7);
    cout << "                                       " << endl;
    gotoxy(5, 8);
    cout << "                                       " << endl;
    gotoxy(5, 9);
    cout << "                                       " << endl;
    gotoxy(5, 10);
    cout << "                                       " << endl;
    gotoxy(5, 11);
    cout << "                                       " << endl;
    gotoxy(5, 12);
    cout << "                                       " << endl;

    return opt;
}

void create()
{
    // dimention for array
    int dFact, dProducts;

    // Sales Check attributes
    string name;
    int id;
    string aux_date;
    string date[3]; // d, m, y
    Product detalleProductos[10];
    int total = 0;

    // Product attributes
    string description;
    int cant_product;
    int precio;


    /*/////////////////////////////////////////////creating/////////////////////////////////////////////////*/

    gotoxy(5, 0);
    cout << "CREATE" << endl;

    // Ask for dimention of Sales Check
    gotoxy(7, 2);
    cout << "How many sales check do you want to create?";
    cin >> dFact;
    gotoxy(7, 2);
    cout << "                                           ";

    // Ask for name
    gotoxy(7, 2);
    cout << "Set your fullname: ";
    cin >> name;
    gotoxy(7, 2);
    cout << "                   ";
    cin >> name;

    // Ask for date
    for (int i = 0; i < 3; i++)
    {
        gotoxy(7, 2);
        cout << "Next, set the date of shopping in this order (day / month in number / year): ";
        cin >> aux_date;
        // aux_date = to_string(aux_date);
        date[i] = aux_date;
        gotoxy(7, 2);
        cout << "                                                                             ";
    }

    gotoxy(7, 2);
    cout << "How many products do you want to buy? (Max. 10 items): ";
    cin >> dProducts;
    gotoxy(7, 2);
    cout << "                                                       ";

    // Ask for product
    for (int i = 0; i < dProducts; i++)
    {
        gotoxy(7, 2);
        cout << "Please enter the product description >>> ";
        cin >> description;
        detalleProductos[i].description = description;
        gotoxy(7, 2);
        cout << "                                         ";

        gotoxy(7, 2);
        cout << "Please enter the quantity >>> ";
        cin >> cant_product;
        detalleProductos[i].cant = cant_product;
        gotoxy(7, 2);
        cout << "                              ";

        gotoxy(7, 2);
        cout << "Please enter the price >>> ";
        cin >> precio;
        detalleProductos[i].precio = precio;
        gotoxy(7, 2);
        cout << "                           ";
    }

    for (int i = 0; i < dProducts; i++)
    {
        total = total + detalleProductos[i].precio * detalleProductos[i].cant;
    }

    for (int i = 0; i < dFact; i++)
    {
        facturas[i].name = name;
        facturas[i].ID = id++;

        facturas[i].date[0] = date[0];
        facturas[i].date[1] = date[1];
        facturas[i].date[2] = date[2];


        facturas[i].detalleProductos.cant = detalleProductos.cant;
        facturas[i].detalleProductos.description = detalleProductos.description;
        facturas[i].detalleProductos.precio = detalleProductos.precio;

        facturas[i].total = total;

        /*
        {
            name,
            id++,
            date, // d, m, y
            detalleProductos,
            total
        };
        */
    };
}

}

void create_masssive()
{
}

void show_data()
{
}

void search_data()
{
}

void upgrade()
{
}

void delete_some_data()
{
}

void save()
{
}

void best_client()
{
}

void higher_product()
{
}

void month_that_sold_the_most()
{
}

void graph()
{
}

void program()
{
    switch(menu())
    {
    case 1:
        create();
        break;
    case 2:
        create_masssive();
        break;
    case 3:
        show_data();
        break;
    case 4:
        search_data();
        break;
    case 5:
        upgrade();
        break;
    case 6:
        delete_some_data();
        break;
    case 7:
        save();
        break;
    case 8:
        best_client();
        break;
    case 9:
        higher_product();
        break;
    case 10:
        month_that_sold_the_most();
        break;
    case 11:
        graph();
        break;
    }
}

int main()
{
    program();
    return 0;
}



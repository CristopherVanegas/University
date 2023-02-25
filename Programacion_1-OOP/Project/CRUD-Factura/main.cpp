#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

void gotoxy(int x,int y);
int menu();
bool app();
void create();
void create_massive();
void show();
void search_sales_check();
int searchForID();

int indxForSearchForProduct[255];
int qSearchForProduct = 0;
void searchForProduct();

void upgrade();
void delete_function();
void save_or_charge_data();
void best_client();
void best_product();
void best_month();          // SHOULD BE CORRECTED TO YEAR THAT SOLD THE MOST.
void bar_grafic();


struct Product
{
    string description;
    int cant;
    int precio;

};

int qSalesChecks;
int qProducts;
int qTotalSalesChecks = 0;

struct Factura
{
    string name;
    int ID = 99999;
    string date[3]; // d, m, y
    Product detalleProductos[10];
    int subtotal;
    int total;
    bool mostrar = true;
};

Factura facturas[255];


int main()
{
    srand(time(NULL));
    for (;;)
    {
        if (app())
            continue;
        else
            break;
    }
    return 0;
}

bool app()
{
    switch (menu())
    {
    case 1:
        create();
        break;

    case 2:
        create_massive();
        break;

    case 3:
        show();
        break;

    case 4:
        search_sales_check();
        break;

    case 5:
        upgrade();
        break;

    case 6:
        delete_function();
        break;

    case 7:
        save_or_charge_data();
        break;

    case 8:
        best_client();
        break;

    case 9:
        best_product();
        break;

    case 10:
        best_month();
        break;

    case 11:
        bar_grafic();
        break;

    case 12:
        return false;
        break;
    }

    return true;
}

int menu()
{
    int opt;

    system("cls");
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
        cout << " [7]    Save or Charge Data" << endl;
        gotoxy(5, 9);
        cout << " [8]    Best client!" << endl;
        gotoxy(5, 10);
        cout << " [9]    Higher product!" << endl;
        gotoxy(5, 11);
        cout << " [10]   Month that sold the most!" << endl;
        gotoxy(5, 12);
        cout << " [11]   Graph of sales chart" << endl;

        gotoxy(5, 13);
        cout << " [12]   Exit" << endl;

        cin >> opt;
        cin.get();
    }
    while (opt <= 0 || opt > 12);

    return opt;
}

void create()
{
    char answer;
    string clientName, clientSurname;

    do
    {
        system("cls");

        gotoxy(1, 1);
        cout << " -- Enter 's' to send data. ";
        facturas[qTotalSalesChecks].ID = qTotalSalesChecks;
        gotoxy(1, 2);
        cout << "Please enter the client's name: ";
        getline(cin, clientName);
        gotoxy(1, 3);
        cout << "Please enter the client's surname: ";
        getline(cin, clientSurname);

        facturas[qTotalSalesChecks].name = clientName + " " + clientSurname;

        gotoxy(1, 4);
        cout << "Please enter in number what day is today: ";
        cin >> facturas[qTotalSalesChecks].date[0];
        gotoxy(1, 5);
        cout << "Please enter in number what month is today: ";
        cin >> facturas[qTotalSalesChecks].date[1];
        gotoxy(1, 6);
        cout << "Please enter in number what year is today: ";
        cin >> facturas[qTotalSalesChecks].date[2];
        gotoxy(1, 8);
        cout << "How many products do you want to list? ";
        cin >> qProducts;
        cin.get();


        int y = 0;
        for (int j = 0; j < qProducts; j++)
        {
            gotoxy(1, y + 9);
            cout << "Please enter the product " << j + 1 << " description: ";
            getline(cin, facturas[qTotalSalesChecks].detalleProductos[j].description);
            cin.get();

            gotoxy(1, y + 10);
            cout << "Please enter the product " << j + 1 << " price: ";
            cin >> facturas[qTotalSalesChecks].detalleProductos[j].precio;
            cin.get();

            gotoxy(1, y + 11);
            cout << "Please enter the " << j + 1 << " quantity: ";
            cin >> facturas[qTotalSalesChecks].detalleProductos[j].cant;
            cin.get();

            facturas[qTotalSalesChecks].subtotal=facturas[qTotalSalesChecks].detalleProductos[j].precio*facturas[qTotalSalesChecks].detalleProductos[j].cant;

            facturas[qTotalSalesChecks].total=(facturas[qTotalSalesChecks].subtotal+(facturas[qTotalSalesChecks].subtotal*0.12));

            y = y + 4;
        }

        do
        {
            system("cls");
            gotoxy(5, 5);
            cout << "Do you want to create another sales check? Only (y / n) ";
            answer = getche();
            cin.get();
        }
        while ((answer != 'y') && (answer != 'n'));

        qTotalSalesChecks++;
        // system("cls");
    }
    while (answer == 'y');
}

void create_massive()
{
    char answer;
    int quantity, iEnd;

    system("cls");

    gotoxy(1,1);
    cout << "CREATE MASSIVE  --  PRESS 'q' TO GO BACK TO MENU";

    gotoxy(1, 2);
    cout << "How many sales check do you want to create? Only number: ";
    cin >> quantity;

    iEnd = qTotalSalesChecks + quantity;

    for (int i = qTotalSalesChecks; i < iEnd; i++)
    {
        facturas[i].ID = qTotalSalesChecks;
        facturas[i].name = "Client " + to_string(qTotalSalesChecks);

        facturas[i].date[1] = to_string(1 + rand() % 12);  // month

        if (facturas[i].date[1] == "2")
        {
            facturas[i].date[0] = to_string(1 + rand() % 28);  // day for february
        }
        else
        {
            facturas[i].date[0] = to_string(1 + rand() % 31);  // day for other months
        }

        facturas[i].date[2] = to_string(2004 + rand() % (2024 - 2004)); // years from 2004 to 2023



        // random int to create random quantity of products.
        int r = 1 + rand() % 10;

        for (int j = 0; j < r; j++)
        {
            facturas[i].detalleProductos[j].description  = "Product " + to_string(j + 1);

            facturas[i].detalleProductos[j].precio = 20 + rand() % 1100;

            facturas[i].detalleProductos[j].cant = 1 + rand() % 10;

            facturas[i].subtotal=facturas[i].detalleProductos[j].precio*facturas[i].detalleProductos[j].cant;

            facturas[i].total=(facturas[i].subtotal+(facturas[i].subtotal*0.12));
        }

        qTotalSalesChecks++;    // Adds the massive iterator to the actual count of sales checks.
    }

    Sleep(250);
}

void show()
{
    int y = 2;

    system("cls");
    gotoxy(1, 1);
    cout << "SHOW  --  PRESS 'q' TO GO BACK TO MENU";

    for (int j = 0; j < qTotalSalesChecks; j++)
    {
        if (facturas[j].mostrar)
        {
            gotoxy(2, y++);
            cout << facturas[j].date[0] << "/ " << facturas[j].date[1] << " /" << facturas[j].date[2];
            gotoxy(2, y++);
            cout << "Sales Check ID = " << facturas[j].ID;
            gotoxy(2, y++);
            cout << "Fullname: " << facturas[j].name;

            for (int k = 0; k < 10; k++)
            {
                if (facturas[j].detalleProductos[k].description != "")
                {
                    gotoxy(2, y++);
                    cout << "Product " << k + 1;
                    gotoxy(2, y++);
                    cout << "---| Description: " << facturas[j].detalleProductos[k].description;
                    gotoxy(2, y++);
                    cout << "---| Price: " << facturas[j].detalleProductos[k].precio;
                    gotoxy(2, y++);
                    cout << "---| Quantity: " << facturas[j].detalleProductos[k].cant;
                    cout << endl;
                }
            }

            gotoxy(2, y++);
            cout<<  "---| SubTotal: " << facturas[j].subtotal;
            cout << endl;
            gotoxy(2, y++);
            cout<<  "---| Total: " << facturas[j].total;
            cout << endl;


            y = y + 3;

            cout << endl;
            cout << endl;
        }
    }

    char answer;

    answer = getche();

    if (answer == 'q')
        system("cls");
}

void search_sales_check()
{
    int opt;
    char answer;

    system("cls");

    gotoxy(1, 1);
    cout << "SEARCH FOR ID OR PRODUCT  --  PRESS 'q' TO GO BACK TO MENU";

    gotoxy(1, 2);
    cout << "Do you want to search for... Select and option, just the number: ";

    gotoxy(5, 3);
    cout << " [1]    Search for ID" << endl;

    gotoxy(5, 4);
    cout << " [2]    Search for PRODUCT" << endl;

    cin >> opt;
    cin.get();

    switch(opt)
    {
    case 1:
    {
        int indx = searchForID();
        int y = 6;

        gotoxy(7, y++);
        cout << facturas[indx].date[0] << "/ " << facturas[indx].date[1] << " /" << facturas[indx].date[2];
        gotoxy(7, y++);
        cout << "Sales Check ID " << facturas[indx].ID;
        gotoxy(7, y++);
        cout << "Fullname " << facturas[indx].name;

        for (int k = 0; k < 10; k++)
        {
            if (facturas[indx].detalleProductos[k].description != "")
            {
                gotoxy(7, y++);
                cout << "Product " << k + 1;
                gotoxy(7, y++);
                cout << "---| Description: " << facturas[indx].detalleProductos[k].description;
                gotoxy(7, y++);
                cout << "---| Price: " << facturas[indx].detalleProductos[k].precio;
                gotoxy(7, y++);
                cout << "---| Quantity: " << facturas[indx].detalleProductos[k].cant;
            }
        }

        gotoxy(7, y++);
        cout << "|--------------------------|";
        gotoxy(7, y++);
        cout<<  "---| SubTotal: " << facturas[indx].subtotal;
        gotoxy(7, y++);
        cout<<  "---| Total: " << facturas[indx].total;

        cout << endl;
        cout << endl;

    }
    break;

    case 2:
    {
        int y = 6;

        searchForProduct();

        for (int i = 0; i < qSearchForProduct; i++)
        {
            gotoxy(7, y++);
            cout << facturas[indxForSearchForProduct[i]].date[0] << "/ " << facturas[indxForSearchForProduct[i]].date[1] << " /" << facturas[indxForSearchForProduct[i]].date[2];
            gotoxy(7, y++);
            cout << "Sales Check ID " << facturas[indxForSearchForProduct[i]].ID;
            gotoxy(7, y++);
            cout << "Fullname " << facturas[indxForSearchForProduct[i]].name;

            for (int k = 0; k < 10; k++)
            {
                if (facturas[indxForSearchForProduct[i]].detalleProductos[k].description != "")
                {
                    gotoxy(7, y++);
                    cout << "Product " << k + 1;
                    gotoxy(7, y++);
                    cout << "---| Description: " << facturas[indxForSearchForProduct[i]].detalleProductos[k].description;
                    gotoxy(7, y++);
                    cout << "---| Price: " << facturas[indxForSearchForProduct[i]].detalleProductos[k].precio;
                    gotoxy(7, y++);
                    cout << "---| Quantity: " << facturas[indxForSearchForProduct[i]].detalleProductos[k].cant;
                    gotoxy(7, y++);
                    cout<<  "---| SubTotal: " << facturas[indxForSearchForProduct[i]].subtotal;
                    gotoxy(7, y++);
                    cout<<  "---| Total: " << facturas[indxForSearchForProduct[i]].total;
                    cout << endl;
                    cout << endl;
                }

                y = y + 1;

                cout << endl;
                cout << endl;
            }
        }
    }
    break;
    }

    answer = getch();

    if (answer == 'q')
        system("cls");
}

int searchForID()
{
    system("cls");

    int searching_ID;

    gotoxy(1, 2);
    cout << "Please enter the sales check's ID from 0 to " << qTotalSalesChecks - 1 << " to search: ";
    cin >> searching_ID;

    return searching_ID;
}

void searchForProduct()
{
    string searching_product;
    qSearchForProduct = 0;

    system("cls");
    gotoxy(1, 2);
    cout << "Please enter the product to search: ";
    getline(cin, searching_product);
    // cin.get();

    // cout << searching_product;
    // getline(cin, searching_product);


    int k = 0;

    for (int i = 0; i < qTotalSalesChecks; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (searching_product == facturas[i].detalleProductos[j].description)
            {

                indxForSearchForProduct[k] = i;
                qSearchForProduct++;
                k++;
                break;
            }
        }
    }
}

void upgrade()
{
    char answer;
    int y = 4;
    int id;
    int price;
    system("cls");
    gotoxy(1, 1);
    cout << "UPGRADE  --  PRESS 'q' TO GO BACK TO MENU";

    do
    {

        system("cls");

        /*
                UPDATE
                    > PRODUCT PRICE from a specified SALES CHECK ID.
        */

        gotoxy(1, 2);
        cout << "The available sales checks are from ID " << 0 << " to " <<  qTotalSalesChecks-1;
        gotoxy(1, 3);
        cout << "Please enter a valid id to continue... ";
        cin >> id;
        cin.get();

        // SHOW THE SALES CHECK // --------------------------------------------------------------------------//
        gotoxy(2, y++);
        cout << facturas[id].date[0] << "/ " << facturas[id].date[1] << " /" << facturas[id].date[2];
        gotoxy(2, y++);
        cout << "Sales Check ID " << facturas[id].ID;
        gotoxy(2, y++);
        cout << "Fullname " << facturas[id].name;

        for (int k = 0; k < 10; k++)
        {
            if (facturas[id].detalleProductos[k].description != "")
            {
                gotoxy(2, y++);
                cout << "Product " << k + 1;
                gotoxy(2, y++);
                cout << "---| Description: " << facturas[id].detalleProductos[k].description;
                gotoxy(2, y++);
                cout << "---| Price: " << facturas[id].detalleProductos[k].precio;
                gotoxy(2, y++);
                cout << "---| Quantity: " << facturas[id].detalleProductos[k].cant;
            }
        }
        gotoxy(2, y++);
        cout << "---| SubTotal: " << facturas[id].subtotal;
        cout << endl;
        gotoxy(2, y++);
        cout << "---| Total: " << facturas[id].total;
        cout << endl;

        y = y + 3;

        cout << endl;
        cout << endl;

        // --------------------------------------------------------------------------------------------------//


        gotoxy(1, y++);
        cout << "Which product price do you want to upgrade?? ";

        for (int k = 0; k < 10; k++)
        {
            if (facturas[id].detalleProductos[k].description != "")
            {
                gotoxy(4, y++);
                cout << "Product " << k + 1;
                gotoxy(4, y++);
                cout << "---| Price: " << facturas[id].detalleProductos[k].precio;
                y++;
            }
        }

        int product_id;
        gotoxy(1, y++);
        cout << "Please enter 1, 2, 3, ... in order to modify the desired product price >>> ";
        cin >> product_id;
        cin.get();


        int price;
        gotoxy(1, y++);
        cout << "What price do you want? >>> ";
        cin >> price;
        cin.get();

        facturas[id].detalleProductos[product_id-1].precio = price;


        // UPGRADE THE TOTAL AND SUBTOTAL ------------------------------------------------------------------ //
        facturas[id].subtotal = 0;
        facturas[id].total = 0;

        for (int k = 0; k < 10; k++)
        {
            if (facturas[id].detalleProductos[k].description != "")
            {
                facturas[id].subtotal = facturas[id].subtotal + facturas[id].detalleProductos[k].precio;
            }
        }

        facturas[id].total = facturas[id].subtotal - (facturas[id].subtotal * 0.12);


        // ------------------------------------------------------------------------------------------------- //



        system("cls");
        gotoxy(1, 3);
        cout << "Do you want to upgrade another sales check's product?? (only y / n)";
        answer = getch();

    }
    while (answer == 'y');

    answer = getche();
}

void delete_function()
{
    system("cls");
    int n;
    int id;
    int y = 4;
    gotoxy(1, 1);
    cout << "DELETE  --  PRESS 'q' TO GO BACK TO MENU";
    gotoxy(1, 3);
    cout << "The invoices created are the following:";
    for (int j = 0; j < qTotalSalesChecks; j++)
    {
        if (facturas[j].mostrar == true)
        {
            gotoxy(2, y++);
            cout << facturas[j].date[0] << "/ " << facturas[j].date[1] << " /" << facturas[j].date[2];
            gotoxy(2, y++);
            cout << "Sales Check ID " << facturas[j].ID;
            gotoxy(2, y++);
            cout << "Fullname " << facturas[j].name;

            for (int k = 0; k < 10; k++)
            {
                if (facturas[j].detalleProductos[k].description != "")
                {
                    gotoxy(2, y++);
                    cout << "Product " << k + 1;
                    gotoxy(2, y++);
                    cout << "---| Description: " << facturas[j].detalleProductos[k].description;
                    gotoxy(2, y++);
                    cout << "---| Price: " << facturas[j].detalleProductos[k].precio;
                    gotoxy(2, y++);
                    cout << "---| Quantity: " << facturas[j].detalleProductos[k].cant;
                }
            }
            gotoxy(2, y++);
            cout << "---| SubTotal: " << facturas[j].subtotal;
            cout << endl;
            gotoxy(2, y++);
            cout << "---| Total: " << facturas[j].total;
            cout << endl;

            y = y + 3;

            cout << endl;
            cout << endl;
        }
    }
    gotoxy(2, y++);
    cout << "Which invoice do you want to delete ?(Introduce the ID from " << 0 << " to " << qTotalSalesChecks - 1 << ") " << endl;
    gotoxy(2, y++);
    cin >> id;
    do
    {
        if (id > qTotalSalesChecks - 1)
        {
            gotoxy(2, y++);
            cout << "Incorrect ID, send a valid ID";
            gotoxy(2, y++);
            cin >> id;
        }
    }
    while (id > qTotalSalesChecks - 1);

    for (int i = 0; i < qTotalSalesChecks; i++)
    {
        if (id == facturas[i].ID)
        {
            gotoxy(2, y++);
            cout << "Do you want to perform a logical or physical deletion ?(1 for logic, 2 for physical)" << endl;
            gotoxy(2, y++);
            cin >> n;
            switch(n)
            {
            case 1:
                facturas[i].mostrar = false;
                break;

            case 2:
                facturas[i].name = "";
                facturas[i].total = 0;
                facturas[i].subtotal = 0;
                for (int k = 0; k < 10; k++)
                {
                    facturas[i].detalleProductos[k].description = "";
                    facturas[i].detalleProductos[k].precio = 0;
                    facturas[i].detalleProductos[k].cant = 0;
                }
                break;
            }
        }
    }

    char answer;

    answer = getche();

    if (answer == 'q')
        system("cls");
}

void save_or_charge_data()
{

}

void best_client()
{
    float mayor=facturas[0].total;
    int cmayor=facturas[0].ID;
    system("cls");
    gotoxy(1, 1);
    cout << "BEST CLIENT  --  PRESS 'q' TO GO BACK TO MENU";
    for (int j = 0; j < qTotalSalesChecks; j++)
    {
        for (int k = 0; k < 10; k++)
        {
            if (facturas[j].detalleProductos[k].description != "")
            {
                if(mayor<facturas[j].total)
                {
                    mayor=facturas[j].total;
                    cmayor=facturas[j].ID;
                }
            }
        }
    }
    gotoxy(1,2);
    cout<<"The best client is: Client "<<cmayor<<" with $"<<mayor;
    char answer;

    answer = getche();

    if (answer == 'q')
        system("cls");
}

void best_product()
{
    float mayor=facturas[0].detalleProductos[0].cant;
    int pmayor=facturas[0].ID;
    string cmayor=facturas[0].name;
    system("cls");
    gotoxy(1, 1);
    cout << "BEST PRODUCT  --  PRESS 'q' TO GO BACK TO MENU";
    for (int j = 0; j < qTotalSalesChecks; j++)
    {
        for (int k = 0; k < 10; k++)
        {
            if (facturas[j].detalleProductos[k].description != "")
            {
                if(mayor<facturas[j].detalleProductos[k].cant)
                {
                    mayor=facturas[j].detalleProductos[k].cant;
                    pmayor=k+1;
                    cmayor=facturas[j].name;
                }
            }
        }
    }
    gotoxy(1,2);
    cout<<"The product client is: Product "<<pmayor<<" from "<<cmayor<<" with "<<mayor;
    char answer;

    answer = getche();

    if (answer == 'q')
        system("cls");
}


void best_month()
{
    string mmayor=facturas[0].date[1];
    int tmayor=facturas[0].total;
    system("cls");
    gotoxy(1, 1);
    cout << "BEST MONTH PER YEAR  --  PRESS 'q' TO GO BACK TO MENU";

    for (int j = 0; j < qTotalSalesChecks; j++)
    {
        for (int k = 0; k < 10; k++)
        {
            if (facturas[j].detalleProductos[k].description != "")
            {
                if(tmayor<facturas[j].total)
                {
                    tmayor=facturas[j].total;
                    mmayor=facturas[j].date[1];
                }
                gotoxy(1,j+2);
                cout<<"the best month of the year "<<facturas[j].date[2]<<" was "<<facturas[j].date[1]<<" with $"<<facturas[j].total;
            }
        }
    }

    char answer;

    answer = getche();

    if (answer == 'q')
        system("cls");
}


void bar_grafic()
{
    system("cls");
    gotoxy(1, 1);
    cout << "BAR GRAPHIC  --  PRESS 'q' TO GO BACK TO MENU";
    for(int i=0; i<facturas[0].total; i++)
    {
        gotoxy(i,2);
        cout<<"|";
    }


    char answer;

    answer = getche();

    if (answer == 'q')
        system("cls");
}

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

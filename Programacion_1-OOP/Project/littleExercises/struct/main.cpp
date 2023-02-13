#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    return 0;
}

void factura()
{
    struct
    {
        string name;
        string surname;
        int id;
        string date[3]; // d, m, y
        int total;

        date[0] = to_string(1 + rand()%30);
        date[1] = to_string(1 + rand()%12);
        date[2] = to_string(2019 + rand()%2023);



    } factura;
}


#include <iostream>
#include <time.h>

using namespace std;

int d = 12;
string nombres[12];
int sueldos[12];
int descuen[12];

void setNames(int d);
void setSueldos(int d);
void showData(int d);
int mayorSueldo(int d);
float promedio(int d);

int main()
{
    srand(time(NULL));
    setNames(d);
    setSueldos(d);
    showData(d);

    cout << "La persona con el sueldo mayor es: " << nombres[mayorSueldo(d)] << endl;
    cout << "El promedio es de: " << promedio(d) << endl;
    return 0;
}


void setNames(int d) {
    for (int i = 0; i < d; i++) {
        cout << ">>> Enter the name for person " << i + 1 << ": "; cin >> nombres[i]; cout << endl;
    }

}

void setSueldos(int d) {
    for (int i = 0; i < d; i++) {
        sueldos[i] = 500 + rand() % 1800;
    }
}

int mayorSueldo(int d) {
    int mayor = sueldos[0];
    int indiceNumMayor;

    for (int i = 0; i < d; i++) {
        if (mayor < sueldos[i]) {
            mayor = sueldos[i];
            indiceNumMayor = i;
        }
    }
    return indiceNumMayor;
}

float promedio(int d) {
    int a = 0;

    for (int i = 0; i < d; i++) {
        a = a + sueldos[i];
    }
    return a / d;
}

void showData(int d) {
    for (int i = 0; i < d; i++) {
        cout << nombres[i] << "  ";
    }

    cout << endl;

    for (int i = 0; i < d; i++) {
        cout << sueldos[i] << "  ";
    }

    cout << endl;
}

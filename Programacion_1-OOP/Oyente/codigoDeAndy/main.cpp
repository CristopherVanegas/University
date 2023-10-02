#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

using namespace std;

// Definición de la clase Asiento
class Asiento {
public:
    int PosicionX;
    int PosicionY;
    string Codigo;
    char Ocupado;
    bool Canguil;

    // Constructor de la clase Asiento
    Asiento(int posX, int posY) {
        PosicionX = posX;
        PosicionY = posY;
        Codigo = to_string(posX) + to_string(posY);
        Ocupado = (rand() % 2 == 0) ? '*' : ' ';
        Canguil = (Ocupado == '*') ? (rand() % 2 == 0) : false;
    }
};

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    const int SALAS = 10;
    const int FILAS = 8;
    const int COLUMNAS = 30;

    // Inicializar la semilla para generar números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Crear el arreglo de 3 dimensiones para las salas de cine
    Asiento cines[SALAS][FILAS][COLUMNAS];

    // Llenar el arreglo con objetos de tipo Asiento
    for (int sala = 0; sala < SALAS; sala++) {
        for (int fila = 0; fila < FILAS; fila++) {
            for (int columna = 0; columna < COLUMNAS; columna++) {
                cines[sala][fila][columna] = Asiento(columna, fila);
            }
        }
    }

    // Mostrar el estado de ocupación de los asientos
    for (int sala = 0; sala < SALAS; sala++) {
        gotoxy(0, sala * (FILAS + 1));
        cout << "Sala " << sala + 1 << ":" << endl;
        for (int fila = 0; fila < FILAS; fila++) {
            for (int columna = 0; columna < COLUMNAS; columna++) {
                Asiento asiento = cines[sala][fila][columna];
                cout << asiento.Ocupado;
            }
            cout << endl;
        }
    }

    return 0;
}

#include <iostream>
#include <time.h>

using namespace std;

void mayor(int arrN[], int d);
void menor(int arrN[], int d);

int main()
{
    srand(time(NULL));

    int d = 15, arrN[d];
    for (int i = 0; i < d; i++) {
        arrN[i] = rand() % 101;
        cout << arrN[i] << "  ";
    }

    menor(arrN, d);
    mayor(arrN, d);

    return 0;
}

void mayor(int arrN[], int d) {
    // numero mayor
    int mayor = arrN[0];
    cout << endl << "Numero mayor inicial es: " << mayor << endl;

    for (int i = 0; i < d; i++) {
        if (mayor < arrN[d-i-1]) {
            mayor = arrN[d-i-1];
        }
    }

    cout << "Numero mayor es: " << mayor << endl;
}

void menor(int arrN[], int d) {
    // numero menor
    int menor = arrN[0];
    cout << endl << "Numero menor inicial es: " << menor << endl;

    for (int i = 0; i < d; i++) {
        if (menor > arrN[d-i-1]) {
            menor = arrN[d-i-1];
        }
    }

    cout << "Numero menor es: " << menor << endl;
}

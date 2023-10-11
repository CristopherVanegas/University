// Est. Cristopher Vanegas

#include <iostream>

using namespace std;
void pedirTresNumeros();
void convertirMsAKh();


int main()
{
    pedirTresNumeros();
    convertirMsAKh();

    return 0;
}

void convertirMsAKh()
{
    int ms;
    float km;
    cout << "Velocidad en m/s: ";
    cin >> ms;
    km = (ms * 3600)/1000;
    cout << "La velocidad en k/h es " << km;

    cout << endl;
    cout << endl;
    cout << endl;
}

void pedirTresNumeros()
{
    int a, b, c, arr[3];
    cout << "Primer numero: ";
    cin >> a;
    cout << "Segundo numero: ";
    cin >> b;
    cout << "Tercer numero: ";
    cin >> c;

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;

    // desordenado
    cout << endl << "Desordenado Menor a Mayor" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i];
    }

    // ordena menor a mayor
    for (int i = 0; i < 3; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (arr[i] > arr[j])
            {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }


    // ordenado
    cout << endl << "Ordenado" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i];
    }

    cout << endl;
    cout << endl;
    cout << endl;
}

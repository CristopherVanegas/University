#include <iostream>

using namespace std;

int main()
{
    int x = 4;
    int *px = &x;
    int **ppx = &px;
    cout << "Valor de x: " << x << endl;
    cout << "Valor de x: " << *px << endl;
    cout << "Valor de x: " << **ppx << endl;
    return 0;
}

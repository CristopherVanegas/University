#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

char abc[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

int main()
{
    srand(time(NULL));
    cout << abc[1 + rand()%10] << endl;

    return 0;
}


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    cout << -1 - rand() % -3;
    return 0;
}

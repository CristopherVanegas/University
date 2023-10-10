#include <iostream>

using namespace std;

int main()
{
    int arr {6};
    // arr{6} = [1, 2, 3, 3, 4, 5, 6];
    for (int i = 0; i < sizeof(arr); i++) {
        arr[i] = i + 1;
        cout << arr[i];
    }
    return 0;
}

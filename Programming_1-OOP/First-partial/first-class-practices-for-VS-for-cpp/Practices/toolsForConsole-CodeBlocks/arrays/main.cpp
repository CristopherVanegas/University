#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    int nums[] = {0, 0, 0, 0, 0};
    nums[0] = 1;
    nums[1] = 2;
    nums[2] = 3;
    nums[3] = 4;
    nums[4] = 5;

    int limit = sizeof(nums);

    for (int i = 0; i < limit; i++) {
            cout << nums[i] << endl;
    }
    return 0;
}

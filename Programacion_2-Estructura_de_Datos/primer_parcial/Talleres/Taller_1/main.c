#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[3][3] =
    {
        {12, 34, 25},
        {16, 18, 40},
        {20, 32, 50}
    };

    printf("|--- MATRIX A---|\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int matrix[3][3];

void fill();
void show();

int main()
{
    srand(time(NULL));
    printf("Random Values for Matrix!\n");
    fill();
    show();

    return 0;
}


void fill()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            matrix[i][j] = 1 + rand() % 50;
        }
    }
}

void show()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("  %d  ", matrix[i][j]);
        }

        printf("\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void to_zero(int (*arr)[5], int row, int col);
int main()
{
    int arr[5][5] = {0};
    srand(time(NULL));
    to_zero(arr, 5, 5);
    return 0;
}
void to_zero(int (*arr)[5], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (i > j)
            {
                arr[i][j] = 0;
            }
            else
            {
                arr[i][j] = rand() % 9 + 0;
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
}
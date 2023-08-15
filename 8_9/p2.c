#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10] = {0};
    int i = 0;
    int j = 0;
    int max = 0;
    int temp = 0;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    for (i = 0; i < 10; i++)
    {
        max = i;
        for (j = i + 1; j < 10; j++)
        {
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        if (max != i)
        {
            temp = arr[i];
            arr[i] = arr[max];
            arr[max] = temp;
        }
    }
    printf("\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
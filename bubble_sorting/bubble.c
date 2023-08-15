// 冒泡排序

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10] = {0};
    int i = 0;
    int j = 0;
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

//冒泡排序算法
    for (i = 1; i < 10; i++)
    {
        for (j = 0; j < 10 - i; j++)
        {
            if (arr[j] > arr[j + 1])  //从小到大排
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
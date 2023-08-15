//插入排序

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

//插入排序算法
    for (i = 1; i < 10;i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j>=0 && arr[j]>temp)  //从小到大排
            {
                arr[j+1] = arr[j];
                j--;
            }
        arr[j + 1] = temp;
    }

    printf("\n");

    for (i = 0; i < 10; i++)
    {
            printf("%d ", arr[i]);
    }
        return 0;
}
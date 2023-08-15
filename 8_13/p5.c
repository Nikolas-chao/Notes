#include <stdio.h>

int main()
{
    int arr[10] = {0};
    int arr1[10] = {0};
    int i = 0;
    int j = 0;
    int little = 0;
    int temp = 0;

    for (i = 0; i < 10;i++)
    {
        printf("input num:> ");
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < 10; i++)
    {
        little = i;
        for (j = i + 1; j < 10; j++)
        {
            if (arr[j] < arr[little])
            {
                little = j;
            }
        }
        if (little != i)
        {
            temp = arr[i];
            arr[i] = arr[little];
            arr[little] = temp;
        }
    }
    j = 0;
    for (i = 0; i < 10;i++)
    {
        if(i%2==0)
        {
            arr1[j] = arr[i];
            j++;
        }
        if(i%2!=0)
        {
            arr1[10 - j] = arr[i];
        }
      
    }
    for (i = 0; i < 10;i++)
    {
        printf("%d ", arr1[i]);
    }
        return 0;
}
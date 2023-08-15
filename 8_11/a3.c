//冒泡排序函数封装
//void bubble_sort(int *array, int n);

#include <stdio.h>

void bubble_sort(int *array, int n);

int main()
{
    int arr[6] = {0};
    int i = 0;
    int num = 0;
    int n = 6;

    for (i = 0; i < 6;i++)
    {
        printf("input num:> ");
        scanf("%d", &num);
        arr[i] = num;
    }
    bubble_sort(arr, n);

    return 0;
}

void bubble_sort(int *arr, int n)
{
    int i = 0;
    int j = 0;
    int temp = 0;
    for (i = 1; i < n;i++)
    {
        for (j = 0; j < n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (i = 0; i < n;i++)
    {
        printf("%d ", arr[i]);
    }
}
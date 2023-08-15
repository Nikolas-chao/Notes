// 输入2个数组，对应值相加，得到最大值
#include <stdio.h>

int arr_max(int*arr1,int*arr2,int *arr,int n);

int main()
{
    int arr1[5] = {12,34,56,10,7};
    int arr2[5] = {45,12,80,37,24};
    int arr[5] = {0};
    int max = 0;
    int n = 5;

    max = arr_max(arr1, arr2, arr, n);
    printf("max is:>%d\n", max);

    return 0;
}

int arr_max(int *arr1, int *arr2, int *arr, int n)
{
    int i = 0;
    int j = 0;
    int max = 0;
    for (i = 0; i < n;i++)
    {
        arr[i] = arr1[i] + arr2[i];
    }
    for (i = 0; i < n;i++)
    {
    printf("%d ", arr[i]);
    }
    printf("\n");

    for (j = 0; j < n;j++)
    {
        if(arr[j]>max)
        {
            max = arr[j];
        }
    }
    return max;
}
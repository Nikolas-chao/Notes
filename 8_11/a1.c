// 输入整数数组，得到最大值
#include <stdio.h>

int arr_Max(int *arr, int n);

int main()
{
    int arr[10] = {0};
    int i = 0;
    int num = 0;
    int max = 0;
    int n = 0;

    for (i = 0; i < 10; i++)
    {
        printf("input num:>");
        scanf("%d", &num);
        arr[i] = num;
        n++;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    max = arr_Max(arr, n);

    printf("max is:>%d\n", max);

    return 0;
}

int arr_Max(int *arr, int n)
{
    int i = 0;
    int j = 0;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

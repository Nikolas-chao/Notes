// 数组 a 中存放一个递增数列。输入一个整数 x,并将它插入到数组 a 中，使该数组仍为一个递增数列。
#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    int new_arr[11] = {0};
    int num = 0;
    int i = 0;
    int j = 0;
    int temp = 0;

    printf("input num:> ");
    scanf("%d",&num);

    for (i = 0; i < 10; i++)
        {
            new_arr[i] = arr[i];
        }
    new_arr[i] = num;

    for (i = 1; i < 11;i++)
    {
            temp = new_arr[i];
            j = i - 1;
            while (j >= 0&&new_arr[j]>temp)
            {
                new_arr[j + 1] = new_arr[j];
                j--;
            }
            new_arr[j + 1] = temp;
    }

    
            return 0;
}
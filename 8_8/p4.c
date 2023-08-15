// 打印filb的前n个数组，存入到数组中，统计个数打印出来

#include <stdio.h>

int main()
{
    int i = 0;
    int num = 0;
    int arr[100] = {1,1,0};
    int count = 1;

    printf("input:>");
    scanf("%d", &num);

    for (i = 2; i <= num;i++)
    {  
        arr[i] = arr[i - 1] + arr[i - 2];
        count++;
        if (arr[i]> num)
        {
            break;
        }
        
    }
    for (i = 0; i < count;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n%d以内的斐波那契数有%d个\n", num, count);

    return 0;
}
// 输入一个数字，得到各个位置上数字，输出最大的数字和最小数字

#include <stdio.h>

int main()
{
    int num = 0;
    int count = 0;
    int arr[10] = {0};
    int i = 0;
    int temp = 0;
    int temp_max = 0;
    int temp_min = 0;
    

    printf("input num:>");
    scanf("%d", &num);
    temp = num;

    while(num%10!=0)
    {
        num /= 10;   
        count++;
    }

    for (i = 0; i < count;i++)
        {
             arr[i] = temp % 10;
             temp /= 10;
        }
    for (i = 0; i < count;i++)
    {
        if(temp_max<=arr[i])
        {
            temp_max = arr[i];
        }
        else 
        {
            temp_min = arr[i];
        }
    }
    printf("max is:>%d\n", temp_max);
    printf("min is:>%d\n", temp_min);
    return 0;
}
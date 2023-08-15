// 随机输入数组，去除重复值去重
//{1,1,2,2} --> {1,2}

#include <stdio.h>

int main()
{
    int num = 0;
    int arr[6] = {0};
    int new_arr[6] = {0};
    int i = 0;
    int j = 1;

    for (i = 0; i < 6;i++)
    {
         printf("input num:>");
         scanf("%d", &num);
         arr[i] = num;
    }
    printf("arr is:>");
    for (i = 0; i < 6;i++)
    {
         printf("%d ", arr[i]);
    }
    printf("\n");

    

    for (i = 0; i < 6;i++)
    {
         for (j = 1; j < 6;j++)
         {
             if(arr[i]!=arr[j])
             {
                 new_arr[j] = arr[i];
             }
             if(arr[i]==arr[j])
             {
                 new_arr[j] = 0;
                 break;
             }
             
         }
    }

    printf("new_arr is:>");
    for (j = 0; j < 6;j++)
    {
         printf("%d ", new_arr[j]);
    }
         return 0;
}
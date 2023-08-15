//输入数组，得到第二大值

#include <stdio.h>

int main()
{
    int num = 0;
    int i = 0;
    int j = 0;
    int arr[6] = {0};
    int temp = 0;

    for (i = 0; i < 6;i++)
     {
           printf("input num:>");
           scanf("%d", &num);
           arr[i] = num;
     }

     for (i = 0; i < 6;i++)
     {
           printf("%d ", arr[i]);
     }

     for (i = 0; i < 5;i++)   //由大到小排
     {
           for (j = 0; j < 5;j++)
           {
            if(arr[j]<arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
           }
     } 
     
     printf("\nthe second num is:>%d\n", arr[1]);
     return 0;
}
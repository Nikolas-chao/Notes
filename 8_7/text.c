#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//生成6个不一样的数
int main()
{
    int arr1[7] = {2, 5, 1, 6, 56, 23, 3};
    int arr2[7] = {3, 53, 5, 7, 10, 24, 3};
    int i = 0;
    int j = 0;
    int temp_red = 0;
    int temp_blue = 0;
    int temp = 0;

    for (i = 0;i<7;i++)
    {
        if(i<=5)
        {
            for (j = 0; j <= 5;j++)
            {   
                 if(arr1[i]==arr2[j])
                {
                    temp_red++;
                }
            }
        }
        else
        {
            if(arr1[6]==arr2[6])
            {
                temp_blue = 10;
            }
        }
    }
    temp = temp_blue + temp_red;
    printf("%d\n", temp);
    return 0;
}
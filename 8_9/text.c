#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10] = {0};
    int arr_min[10] = {0};
    int i = 0;
    int j = 0;
    int index = 10;

    int bit = 0;
    int temp = 0;
    int min = 0;

    srand(time(NULL));

    for (i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }

    printf("arr is:>");
    for (i = 0; i < 10; i++) // 打印生成的随机数组
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

   
    for (j = 0; j < 10;j++)
    {
        bit = 0;
        min = arr[0];
        for (i = 1; i < index; i++) // 找数组中的最小值及其下标
        {
             
            if (arr[i] < min)
            {
                min = arr[i];
                bit = i;
            }           
        }

        // arr[bit] = 0;  把最小值计为0

        for (i = bit; i < index; i++) // 把最小值的位置以后的位置往前移
        {
            temp = 0;
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
        printf("arr_del is:>");

        for (i = 0; i < 10; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        arr_min[j] = min;
        index--;
    }
        
        printf("arr_min is:>");
        for (i = 0; i < 10; i++) // 打印存最小值的数组
        {
            printf("%d ", arr_min[i]);
        }
    
    return 0;
}
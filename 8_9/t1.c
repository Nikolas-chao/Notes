#include <stdio.h>

int main()
{
    int num = 0;
    int arr[10] = {0};
    int arr_num[100] = {0};
    int arr_bit[10] = {0};
    int arr_count[10] = {0};
    int i = 0;
  
    int temp = 0;
    int bit = 0;
    int max = 0;
    int bit_second = 0;

    for (i = 0; i < 10;i++)
    {
        printf("input:>");
        scanf("%d", &num);
        arr[i] = num;
    }

    printf("input num is:>");
    for (i = 0; i < 10;i++)
        {
        printf("%d ", arr[i]);
        }
    printf("\n");

    for (i = 0; i < 10;i++)
    {
        temp = arr[i];
            while (temp != 0)
            {
                bit = temp % 10;
                if(bit==0)
                {
                    arr_bit[0]++;
                }
                else if (bit == 1)
                {
                    arr_bit[1]++;    
                }
                else if (bit == 2)
                {
                    arr_bit[2]++;
                }
                else if (bit == 3)
                {
                    arr_bit[3]++;
                }
                else if (bit == 4)
                {
                    arr_bit[4]++;
                }
                else if (bit == 5)
                {
                    arr_bit[5]++;
                }
                else if (bit == 6)
                {
                    arr_bit[6]++;
                }
                else if (bit == 7)
                {
                    arr_bit[7]++;
                }
                else if (bit == 8)
                {
                    arr_bit[8]++;
                }
                else if (bit == 9)
                {
                    arr_bit[9]++;
                }
              
                temp /= 10;
            }
    }

    bit = 0;
    max = arr_bit[0];
    for (i = 0; i < 10;i++)    //打印各数字出现的次数
    {
            printf("%d ", arr_bit[i]);
    }

    printf("\n");

    for (i = 0; i < 10;i++)
    {
        if(arr_bit[i]>max)
        {
            max = arr_bit[i];
            bit = i;
        }
    }
    
    printf("出现最多的数字是%d,出现了%d次\n", bit, max);
    return 0;
}
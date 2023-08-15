// 输入一个数，判断是不是7倍数和含有7的元素，
//打印这个数以内的7的倍数和含7的元素


#include <stdio.h>

int main()
{
    int arr[100] = {0};
    int num = 0;
    int i = 0;
    int j = 0;
    int count = 0;
    int temp = 0;

    printf("input num:>");
    scanf("%d", &num);

    for (i = 7; i <= num;i++)
    {
        if(i%7==0)
            {
                count++;
                arr[j] = i;
                j++;              
            }
        else
        {
                temp = i;
                while(temp!=0)
                {
                    if(temp%10==7)
                    {
                        count++;
                        arr[j++] = i;
                        break;
                    }
                    temp /= 10;
                }
                
        }
    }

        for (i = 0; i < count; i++)
        {
            printf("%d ", arr[i]);
        }
    printf("\n");
    return 0;
}
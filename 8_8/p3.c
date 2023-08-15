//猜数字

#include <stdio.h>


int main()
{
    int arr1[16] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31};
    int arr2[16] = {2, 3, 6, 7, 10, 11, 14, 15, 18, 19, 22, 23, 26, 27, 30, 31};
    int arr3[16] = {4, 5, 6, 7, 12, 13, 14, 15, 20, 21, 22, 23, 28, 29, 30, 31};
    int arr4[16] = {8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31};
    int arr5[16] = {16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

    int num = 0;
    int i = 0;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    int temp4 = 0;
    int temp5 = 0;
    int temp = 0;

    printf("arr1 is:>");
    for (i = 0; i < 16;i++)
    {
        printf("%d ", arr1[i]);
    }
    printf("\ninput 0/1:>");
    scanf("%d", &num);

    if(num==1)
    {
        temp1 = arr1[0];
    }
    else
    {
        temp1 = 0;
    }

    num = 0;

    printf("arr2 is:>");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\ninput 0/1:>");
    scanf("%d", &num);


    if (num == 1)
    {
        temp2 = arr2[0];
    }
    else
    {
        temp2 = 0;
    }

    num = 0;

    printf("arr3 is:>");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", arr3[i]);
    }
    printf("\ninput 0/1:>");
    scanf("%d", &num);

    if (num == 1)
    {
        temp3 = arr3[0];
    }
    else
    {
        temp3 = 0;
    }

    num = 0;

    printf("arr4 is:>");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", arr4[i]);
    }
    printf("\ninput 0/1:>");
    scanf("%d", &num);

    if (num == 1)
    {
        temp4 = arr4[0];
    }
    else
    {
        temp4 = 0;
    }

    num = 0;

    printf("arr5 is:>");
    for (i = 0; i < 16; i++)
    {
        printf("%d ", arr5[i]);
    }
    printf("\ninput 0/1:>");
    scanf("%d", &num);

    if (num == 1)
    {
        temp5 = arr5[0];
    }
    else
    {
        temp5 = 0;
    }

    temp = temp1 + temp2 + temp3 + temp4 + temp5;

    printf("you guess num is:> %d\n", temp);

    return 0;
}
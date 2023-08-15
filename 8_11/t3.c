//打印**--每行加1

#include <stdio.h>

void printf_star(int n)
{
    
    int i = 0;
    int j = 0;
    for (i = 1; i <= n;i++)
    {
        for (j = 0; j < i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main()
{
    int num = 0;
    printf("input num:>");
    scanf("%d", &num);
    printf_star(num);
    return 0;
}
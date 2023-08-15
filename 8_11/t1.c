//+ - * /
#include <stdio.h>

int num_plus(int a, int b);
int num_subtract(int a,int b);
int num_multuply(int a,int b);
float num_divide(float a, float b);
int num_remainder(int a, int b);

int main()
{
    int num1 = 0;
    int num2 = 0;
    int num = 0;
    float num3 = 0;
    printf("input num1 and num2:>");
    scanf("%d,%d", &num1, &num2);
    int choose  = 0;
    printf("input choose:>");   
    scanf("%d", &choose);
    printf("\n");
    printf("1--'+';\n2--'-';\n3--'*';\n4--'/';\n5--'%%'.\n");

    switch(choose)
    {
        case 1:
            num = num_plus(num1, num2);
            printf("%d + %d = %d\n", num1,num2,num);
            break;
        case 2:
            num = num_subtract(num1, num2);
            printf("%d - %d = %d\n", num1, num2, num);
            break;
        case 3:
            num = num_multuply(num1, num2);
            printf("%d * %d = %d\n", num1, num2, num);
            break;
        case 4:
            num3 = num_divide(num1, num2);
            printf("%d / %d = %.2f\n", num1, num2, num3);
            break;
        case 5:
            num = num_remainder(num1, num2);
            printf("%d %% %d = %d\n", num1, num2, num);
            break;
    }

    return 0;
}

int num_plus(int a, int b)
{
    return (a + b);
}
int num_subtract(int a, int b)
{
    return (a - b);
}
int num_multuply(int a, int b)
{
    return (a * b);
}
float num_divide(float a, float b)
{
    return (a / b);
}
int num_remainder(int a,int b)
{
    return (a %= b);
}

//判断是不是素数

#include <stdio.h>
#include <math.h>

int is_prime(int a);

int main()
{
    int num = 0;

    printf("input num:>");
    scanf("%d", &num);

    if (is_prime(num) == 1)
    {
        printf("%d是素数\n", num);
    }
    else if (is_prime(num) == 0)
    {
        printf("%d不是素数\n", num);
    }
    return 0;
}

 int is_prime(int n)
{
	//是素数返回1，不是素数返回0
	//2到n-1
	int j = 0;
    if(n==1)
        return 0;
    
	for (j = 2; j<=sqrt(n); j++)
	{
		if (n % j == 0)
			
            return 0;
	}
        return 1;
 }
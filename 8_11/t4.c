#include <stdio.h>
#include <stdbool.h>

bool isprime(int val)
{
    int i = 0;
    for (i = 2; i < val; i++)
    {
        if(val%i==0)
        {
            break;
        }
    }
    if(i==val)
        return true;
    else
        return false;
}

int main()
{
    int m = 0;
    scanf("%d", &m);
    if(isprime(m))
        printf("yes!\n");  
    else
        printf("no!\n");

    return 0;
}
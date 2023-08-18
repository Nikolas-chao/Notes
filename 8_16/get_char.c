#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char find_char(char *str,int n);
int main()
{
    char str[5] = {0};
    char seek = 0;
    srand(time(NULL));
    int i = 0;
   

    for (i = 0; i < 5; i++)
    {
        str[i] = rand() % 90 + 48;
    }

    fputs(str, stdout);
    printf("\n");
    
    seek=find_char(str,  5);
    printf("%c\n", seek);

    return 0;
}
char find_char(char *str, int n)
{
   
    int num = 0;
    char ch = 0;
    num = rand() % 4 + 0;
    ch = str[num];
    return ch;
}
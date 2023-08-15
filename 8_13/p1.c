//去空格符

#include <stdio.h>

int main()
{
    char str[20]={"Life is fantastic"};
    char new_str[20] = {0};
    int i = 0;
    int j = 0;
    fputs(str, stdout);
    for (i = 0; i < 20;i++)
    {
            if(str[i]!=' ')
            {
                new_str[j] = str[i];
                j++;
            }
            if(str[i]==' ')
            {
                new_str[j] = str[i + 1];
            }
    }
    fputs(new_str, stdout);

    return 0;
}
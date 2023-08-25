#include <stdio.h>

int main()
{
    char ch = 'e';
    char str[10] = {0};
    str[0] = ch;
    printf("%c", str[0]);
    return 0;
}
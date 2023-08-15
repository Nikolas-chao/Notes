#include <stdio.h>

int main()
{
    char str[20] = {"hello"};
    char str1[10] = {" world"};
    char cat[20] = {0};
    char *sp = NULL;
    char *head = NULL;
    char *sq = NULL;

    sp = str;
    head = str;
    sq = str1;

    while(*sp!='\0')
    {
        sp++;
    }

    while(*sq!='\0')
    {
        *(sp++) = *(sq++);
    }

    fputs(head, stdout);

    return 0;
}
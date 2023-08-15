#include <stdio.h>

int main()
{
    char str[20] = {"hello world"};
    char str1[20] = {0};
    char *sp = NULL;
    char *head = NULL;
    char *temp = NULL;
    int i = 0;

    sp = str;
    head = str1;
    temp = str1;

    while(*sp!='\0')
    {
        *(temp++) = *(sp++);
    }

    fputs(head, stdout);
    return 0;
}
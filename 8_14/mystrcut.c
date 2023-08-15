#include <stdio.h>

int main()
{
    char str[25] = {"helloworldHI I am fine"};
    char str1[5] = {"wor"};
    char str2[5] = {0};
    char *sp = NULL;
    char *sq = NULL;
    char *sw = NULL;
    char *head = NULL;
    int val = 0;

    sp = str;
    sq = str1;
    sw = str2;
    head = str2;

    while(*sq!='\0')
    {
        val = *(++sp) - *(sq);
        if(val==0)
        {
            *(sw++) = *sp;
            sq++;
        }
        
    }

    fputs(head, stdout);

    return 0;
}
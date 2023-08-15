#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* find_numstr(char *str, char *str1);
int main()
{
    char str[20] = {"qwe123214asd"};
    char str1[10] = {0};
    char *sp = NULL;
    sp = find_numstr(str, str1);
    printf("%s\n", sp);

    return 0;
}
char* find_numstr(char *str, char *str1)
{
    int i = 0;
    int j = 0;
    char *head = NULL;
    char *end = NULL;
    head = str;

    while(*(head+i)!='\0')
    {
        if(isdigit(*(head+i)))
        {
            head = head + i;
            end = head;
            break;
        }
        i++;
    }
    while(*(end+j)!='\0')
    {
        if(!isdigit(*(end+j)))
        {
            end = end + j;
            break;
        }
        j++;
    }

    strncpy(str1, head, end - head);
    return str1;
}
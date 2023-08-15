#include <stdio.h>
#include <string.h>

char *del_space(char *str);
int main()
{
    char str[20] = {"he llo wo rl d"};
    char *sp = NULL;
    sp = del_space(str);
    printf("%s\n", sp);

    return 0;
}
char *del_space(char *str)
{
    int i = 0;
    int j = 20;
    char temp = 0;
    char *head = NULL;
    head = str;

    int n = strlen(str);

    for (i = 0; i < n; i++)
    {

        if (*(str + i) == ' ')
        {
            
                     
           *(str + j) = *(str + i );
              
        }
        i++;
        j--;
    }
    return head;
}

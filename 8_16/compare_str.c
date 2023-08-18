#include <stdio.h>
#include <string.h>

void compare_str(char *str1, char *str2);
int main()
{
    char str1[20] = {0};
    char str2[20] = {0};
    printf("input str1: ");
    fgets(str1, sizeof(str1), stdin);
    printf("input str2:");
    fgets(str2, sizeof(str2), stdin);

    compare_str(str1, str2);

    return 0;
}
void compare_str(char *str1, char *str2)
{
    int n = strlen(str1);
    int m = strlen(str2);
    if(n>m)
    {
        printf("str1 is longer");
    }
    else if (n<m)
    {
        printf("str2 is longer");
    }
    else
    {
        printf("str1 is as long as str2");
    }
    
}
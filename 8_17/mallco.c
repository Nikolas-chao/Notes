#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_out(char *str);

int main()
{
    char *str = NULL;
    str_out(str);
    return 0;
}
void str_out(char *str)
{
    str = malloc(20 * sizeof(str));
    if(str==NULL)
    {
        perror("malloc");
        exit(1);
    }
    memset(str, 0, sizeof(str) * 20);

    strcpy(str, "hello world");
    printf("str:%s\n", str);
    free(str);
    str = NULL;
}
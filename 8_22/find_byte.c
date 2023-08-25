#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *find_byte(const void *src, int c,size_t n);

int main()
{
    char str[20] = {"Hello Wolrd-21"};
    char *temp = NULL;
    temp=find_byte(str, 'W', strlen(str));
    printf("%s", temp);
    return 0;
}

void *find_byte(const void *src, int c,size_t n)
{
    char *sc = (char *)src;
    for (int i = 0; i < n;i++)
    {
        if (*(sc++) == c)
        {
            return (void *)(sc - 1);
        }
    }
}
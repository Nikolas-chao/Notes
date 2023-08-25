#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *text_memmmove(void *dest, const void *src, size_t n);

int main()
{
    char str[20] = {"hello world23424"};
    char dest[20] = {0};
    text_memmmove(dest, str, 9);
    fputs(dest, stdout);

    return 0;
}

void *text_memmmove(void *dest, const void *src, size_t n)
{
    char *temp = NULL;
    char *dt = (char *)dest;
    const char *sc = (const char *)src;
    temp = (char*)malloc(sizeof(char) * n);
    memset(temp, 0, sizeof(temp));

    for (int i = 0; i < n;i++)
    {
        *(temp+i)= *(sc + i);
        *(dt + i) = *(temp + i);
    }
    free(temp);
    temp = NULL;
    return dest;
}
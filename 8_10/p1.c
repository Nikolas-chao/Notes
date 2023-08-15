#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//字符数组的使用
int main(int argc, const char *argv[])
{
    char str[100] = {0};
    char str_seek[10] = {0};
    char new_str[100] = {0};
    char str_merge[100] = {0};
    char temp = 0;
    int i = 0;
    int j = 0;

    fgets(str, sizeof(str), stdin);
    // puts(str);

    int n = strlen(str);
    //	getchar();
    // 1.找字符的下标
    printf("input seek char:>");
    scanf("%c", &temp);
    for (i = 0; i < n; i++)
    {
        //  printf("%c", str[i]);
        if (str[i] == temp)
        {
            printf("subscript is:>%d\n", i);
        }
    }
    getchar();
    // 2.找字符串
    printf("input seek strings:>");

    fgets(str_seek, sizeof(str_seek), stdin);
    //  puts(str_seek);

    i = 0;
    int val = 0;
    int k = 0;
    int m = strlen(str_seek);
    while (str_seek[i] != '\0')
    {
        val = str[i] - str_seek[k];
        if(val==0)
        {
           // printf("%d ", i);
            for (j = i; j < i+m; j++)
            {               
                
                val = str[j] - str_seek[k];
                if(val==0)
                {
                    printf("%d ", j);
                }
                else 
                {
                    break;
                }
                k++;
            }
       }
            
        i++;
    }

    printf("\n");
    // 3.赋值
    i = 0;
    while (str[i] != '\0')
    {
        new_str[i] = str[i];
        i++;
    }
    new_str[i] = '\0';

    printf("new_str is:>%s\n", new_str);
    // 4.合并
    int temp_str = 0;

    temp_str = strlen(str) - 1;

    i = 0;
    while (i < temp_str)
    {
        str_merge[i] = str[i];
        i++;
    }
    for (j = temp_str; j < strlen(str_seek) + temp_str; j++)
    {
        str_merge[j] = str_seek[j - temp_str];
    }

    printf("%s\n", str_merge);
    return 0;
}

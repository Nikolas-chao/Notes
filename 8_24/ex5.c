#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    FILE *fp = NULL;
    int set = 0;
    fp = fopen("./info1.txt", "r+");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }

    char str[20] = {0};
    int i = 0;
    srand(time(NULL));
 
    for (i = 0; i < 20;i++)    //生成随机大写字母
    {
        str[i] =rand() % 26 + 65;
    }
  //  puts(str);
    int n = strlen(str);

    for (i = 0; i < n;i++)   //将随机生成的数存到文件info1中
    {
        set = fputc(str[i], fp);
        if(set==EOF)
        {
            perror("fputc");
            exit(-1);
        }
    }

    rewind(fp);
    

    fclose(fp);
    return 0;
}
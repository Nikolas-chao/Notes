//两个字符串找第一个字母不同的位置
#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[20] = {0};
    char str1[10] = {0};
    int i = 0;
    int j = 0;
    int flag = 0;
    int temp = 0;
    printf("input str:");
    fgets(str, sizeof(str), stdin);
    printf("input str1:");
    fgets(str1, sizeof(str1), stdin);

    for (i = 0; i < 20;i++)
{
    str[i] = tolower(str[i]);
    str1[i] = tolower(str1[i]);
}
    for (j = 0; j < 20;j++)
    {
        if(isalpha(str[j])&&isalpha(str1[j]))
        {
            flag = str[j] - str1[j];
            if(flag==0)
            {
                temp = j;
                break;
            }
        }
    }
    printf("%d\n", temp);
    return 0;
}
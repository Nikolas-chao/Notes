// 将源字符串s中所有下标为奇数的字符或 ASCII码 为偶数的字符放入新字符（串）数组t中(规定第一个字符放在第0位中)。
#include <stdio.h>

int main()
{
    char s[20] = {"AABBCCDDEEFF"};
    char t[20] = {0};
    int i = 0;
    int j = 0;

    for (i = 0; i < 20;i++)
    {
        if(i%2!=0||s[i]%2==0)
        {
            t[j] = s[i];
            j++;
        }
    }
    fputs(t, stdout);
    return 0;
}
// 在源字符串找，特定的字符串的操作，统计特定字符串的个数，以及位置所在。

#include <stdio.h>

int main()
{
    char str[50] = {"hello world! how are you.iam fine,and you"};
    char seek_str[4] = {"you"};
    int i = 0;
    int j = 0;
    int k = 0;
    int val = 0;
    int count = 0;

    while(seek_str[i]!='\0')
    {
        val = str[i] - seek_str[i];
        if(val==0)
        {
            for (j = i; j < i+4;j++)
            {
                val = str[j] - seek_str[k];
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
            count++;
        }
        i++;
    }

    printf("count:\n", count);
    return 0;
}
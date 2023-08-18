#include <stdio.h>

typedef struct struct_stu_score
{
    char name[10];
    float Chinese_score;
    float Mate_score;
    float English_score;   
}STU;

STU input_info(STU info);
int main()
{
    int i = 0;
    int j = 0;
    int score[5] = {0};
    int *sp = NULL;
    float stu_average = 0; 
    int sum_stu = 0;
    int sum_sub_Chinese = 0;
    int sum_sub_Math = 0;
    int sum_sub_English = 0;
    int result[3] = {0};

    sp = &score;

    STU info[5];
    for (i = 0; i < 5;i++)
    {
        printf("输入第%d个学生的成绩\n", i + 1);
        info[i] = input_info(info[i]);
    }
 
    for (i = 0; i < 5;i++)
    {
        sum_sub_Chinese += info[i].Chinese_score;
        sum_sub_Math +=info[i].Mate_score;
        sum_sub_English +=info[i].English_score;
    }

    result[0] = sum_sub_Chinese / 5.0;
    result[1] = sum_sub_Math / 5.0;
    result[2] = sum_sub_English / 5.0;
   while(j<3)
   {
        printf("%.2f\t\n", result[j]);
        j++;
   }
   result[j] = '\0';
   return 0;
}
STU input_info(STU info)
{
    printf("input name:>");
    scanf("%s", info.name);
    getchar();

    printf("Chinese score:>");
    scanf("%f", &info.Chinese_score);
    getchar();

    printf("Math score:>");
    scanf("%f", &info.Mate_score);
    getchar();

    printf("English score:>");
    scanf("%f", &info.English_score);
    getchar();

    return info;
}

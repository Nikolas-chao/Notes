// 设计一个师生信息统计表，将老师与学生的信息统计在一个表格中，如果是学生就记录其姓名、性别、角色、所在教室，如果是老师就记录其姓名、性别、角色、所在办公室。*/
//老师和学生的人数
//输入 
//输出 – 角色 /

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct teacher_stu
{
    char name[20];
    char sex[5];   //男，女
    char role[20];  //班主任，语文老师，数学老师，英语老师
    char class[20];  //学生：x年纪x班  老师：203  
}TAS;

void menu();
void sys_teacher_and_students(TAS sp[], int n);
void input_info(TAS sp[], int n);
void output_info(TAS sp[], int n);
void seek_info(TAS sp[], int n);

int main()
{
    TAS *sp = NULL;
    sp = (TAS *)malloc(10 * sizeof(TAS));

    if(sp==NULL)
    {
        perror("malloc");
        exit(1);
    }
    memset(sp, 0, (10 * sizeof(TAS)));

    sys_teacher_and_students(sp, 3);
    free(sp);

    sp = NULL;

    return 0;
}

void menu()
{
    printf("***************************************\n");
    printf("**********欢迎登录学校信息登录系统******\n");
    printf("********0.退出*********1.登记信息********\n");
    printf("********2.查看信息*****3.搜索信息*********\n");
}
void sys_teacher_and_students(TAS sp[],int n)
{
    int input = 0;
    do{
        menu();
        printf("input your choose:>");
        scanf("%d", &input);
        switch (input)
        {
        case 0:
            printf("成功退出！\n");
            break;
        case 1:
            input_info(sp, n);            
            break;
        case 2:
            output_info(sp, n);
            break;
        case 3:
            seek_info(sp, n);
            break;
        default:
            printf("选择无效！\n");
            break;
        }
    }
    while(input);
}

void input_info(TAS sp[], int n)
{
    int i = 0;
    printf("(注：如果您是教师，请输入办公室房间号（如：203）；如果您是学生，请输入年纪和班级（如：三年级2班）)\n");
    for (i = 0; i < n;i++)
    {
        printf("输入第%d个人的信息\n", i + 1);
        printf("input name:>");
        scanf("%s", sp[i].name);

        printf("input sex:>");
        scanf("%s", sp[i].sex);

        printf("input role:>");
        scanf("%s", sp[i].role);

        printf("input class or Office:>");
        scanf("%s", sp[i].class);
    }
}

void output_info(TAS sp[], int n)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    printf("姓名\t性别\t角色\t\t班级\n");
    for (j = 0; j < n;j++)
        {
        printf("%s\t%s\t%s\t\t%s\n", sp[j].name,sp[j].sex, sp[j].role, sp[j].class);
        }
        for (k = 0; k < n;k++)
        {
        
          if(isdigit(sp[k].class[1]))
            {
                count++;
            }
           
        }
    
        
        printf("共有%d个教师%d个学生\n", count, n - count);
}
void seek_info(TAS sp[], int n)
{
        int i = 0;
        int j = 0;
        int flag = 0;
        char seek[20] = {0};
        printf("input seek name:>");
        scanf("%s", seek);
        
            while (strcmp(sp[i].name, seek))
            {
                i++;
            }
         printf("这个人的身份是：%s\n", sp[i].role);
}
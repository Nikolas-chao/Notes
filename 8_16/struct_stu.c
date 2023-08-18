#include <stdio.h>
#include <string.h>

struct struct_info
{
    char name[50];          // 姓名
    int stu_num;            // 学号
    char class[50];         // 班级
    int age;                // 年龄
    char sex[20];           // 性别
    char telephone_num[15]; // 电话
    char native_place[50];  // 籍贯
};

struct struct_info input_struct_info(struct struct_info info);

void printf_info(struct struct_info info);

int main()
{
    struct struct_info info1;

    info1 = input_struct_info(info1);
    printf_info(info1);

    return 0;
}

struct struct_info input_struct_info(struct struct_info info)
{
    bzero(&info, sizeof(info));

    printf("input studen name:> ");
    scanf("%s", info.name);
    getchar();
    // fgets(info.name,sizeof(info.name),stdin);

    printf("input student number:> ");
    scanf("%d", &info.stu_num);
    getchar();

    printf("input student class:> ");
    scanf("%s", info.class);
    getchar();
    // fgets(info.class, sizeof(info.class), stdin);

    printf("input student age:> ");
    scanf("%d", &info.age);
    getchar();

    printf("input student sex:> ");
    scanf("%s", info.sex);
    getchar();
    // fgets(info.sex, sizeof(info.sex), stdin);

    printf("input student telephone number:> ");
    scanf("%s", info.telephone_num);
    getchar();
    // fgets(info.telephone_num, sizeof(info.telephone_num), stdin);

    printf("input student native place:> ");
    scanf("%s", info.native_place);
    
    // fgets(info.native_place, sizeof(info.native_place), stdin);

    return info;
}
void printf_info(struct struct_info info)
{
    printf("name\tstudent num\tclass\t\tage\tsex\ttelephone num\tnative place\n");
    printf("%s\t%d\t\t%s\t%d\t%s\t%s\t%s\n", info.name, info.stu_num, info.class, info.age, info.sex, info.telephone_num, info.native_place);
}

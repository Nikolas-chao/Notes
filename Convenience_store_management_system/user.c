#include "user.h"

USER *read_file_user() // 文件读取
{
    FILE *fp = NULL;
    char ch = 0;
    int ret = 0;

    USER *head = NULL;
    head = malloc(sizeof(USER));
    memset(head, 0, sizeof(USER));
    USER *end = head;
    USER *node = NULL;
    fp = fopen("./User.dat", "r");
    if (fp == NULL)
    {
        printf_log(__FUNCTION__, __FILE__, __LINE__);
        exit(-1);
    }
    ch = fgetc(fp);
    rewind(fp);
    while (ch != EOF)
    {
        node = malloc(sizeof(USER));
        memset(node, 0, sizeof(USER));
        ret = fread(node, sizeof(INFO), 1, fp);
        if (ret != 1)
        {
            printf_log(__FUNCTION__, __FILE__, __LINE__);
        }
        // printf("%s\t%s\n", node->info.name, node->info.password);
        end->next = node;
        end = end->next;
        ch = fgetc(fp);
        fseek(fp, -1, SEEK_CUR);
    }
    fclose(fp);
    return head;
}

void write_file_user(USER *head) // 文件写入
{
    FILE *fp = NULL;
    FILE *fp_txt = NULL;
    fp = fopen("./User.dat", "w");
    fp_txt = fopen("./User.txt", "w");

    USER *end = head;
    end = end->next;
    int set = 0;

    fprintf(fp_txt, "会员姓名\t密码\n");

    while (end != NULL)
    {
        set = fwrite(end, sizeof(INFO), 1, fp);
        if (set != 1)
        {
            printf_log(__FUNCTION__, __FILE__, __LINE__);
        }
        fprintf(fp_txt, "  %s\t\t%s\n", end->info.name, end->info.password);
        end = end->next;
    }
    fclose(fp);
    fclose(fp_txt);
}

USER *input_user(USER *head) // 新建会员
{
    USER *end = head;
    int i = 0;
    USER *node = NULL;
    while (end != NULL)
    {
        node = malloc(sizeof(USER));
        memset(node, 0, sizeof(USER));
        printf("请输入会员名字:>");
        scanf("%s", node->info.name);
        printf("请输入设置密码:>");
        scanf("%s", node->info.password);
        end->next = node;
        end = end->next;
        i++;
        if (i != 0)
            break;
    }
    end = NULL;
    return head;
}

void output_user(USER *head) // 查看会员信息
{
    if (head == NULL)
    {
        perror("没有商品信息,请添加!\n");
        exit(-1);
    }
    USER *end = head;
    end = head->next;
    printf("会员姓名\t密码\n");
    while (end != NULL)
    {
        printf("  %s\t\t %s\n", end->info.name, end->info.password);
        end = end->next;
    }
}

void add_user(USER *head) // 添加会员
{
    USER *end = head;
    end = end->next;
    USER *bef_end = NULL;
    USER *node = NULL;
    node = malloc(sizeof(USER));
    memset(node, 0, sizeof(USER));
    printf("请输入会员名字:>");
    scanf("%s", node->info.name);
    printf("请输入设置的密码:>");
    scanf("%s", node->info.password);
    while (end != NULL)
    {
        if (end->next == NULL)
        {
            bef_end = end;
        }
        end = end->next;
    }
    bef_end->next = node;
    node->next = NULL;
}
void seek_user(USER *head) // 查找会员
{
    if (head->next == NULL)
    {
        perror("没有会员信息,请添加!\n");
        exit(-1);
    }
    char name[20] = {0};
    printf("请输入查找的会员名字:>");
    scanf("%s", name);
    USER *end = NULL;
    end = head->next;
    USER *node = NULL;
    while (end != NULL)
    {
        if (!strcmp(end->info.name, name))
        {
            node = end;
            break;
        }
        end = end->next;
    }
    if (node == NULL)
    {
        perror("没有此人会员信息!\n");
        exit(-1);
    }
    else
    {
        printf("%s\t%s\n", node->info.name, node->info.password);
    }
}
void del_user(USER *head) // 删除会员
{
    if (head->next == NULL)
    {
        perror("没有会员信息,请添加!\n");
        exit(-1);
    }
    char name[20] = {0};
    printf("请输入会员姓名:>");
    scanf("%s", name);
    USER *end = head;
    USER *bef_node = NULL;
    USER *node = NULL;
    while (end != NULL)
    {
        bef_node = end;
        end = end->next;
        if (!strcmp(end->info.name, name))
        {
            node = end;
            break;
        }
    }
    if (node == NULL)
    {
        printf("没有此人会员信息!");
    }
    else
    {
        bef_node->next = node->next;
    }
}
void change_passwprd(USER *head) // 修改密码
{
    if (head->next == NULL)
    {
        perror("没有会员信息,请添加!\n");
        exit(-1);
    }
    char name[20] = {0};
    printf("请输入会员姓名:>");
    scanf("%s", name);
    USER *end = head;
    end = end->next;
    while (end != NULL)
    {
        if (!strcmp(end->info.name, name))
        {
            printf("请输入修改后的密码:>");
            scanf("%s", end->info.password);
        }
        end = end->next;
    }
}
void free_user(USER *head) // 释放链表
{
    USER *end = head;
    while (head != NULL)
    {
        end = head;
        head = head->next;
        free(end);
        end = NULL;
    }
}
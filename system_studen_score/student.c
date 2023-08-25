#include "student.h"

student *create_list(void) // 新建学生信息
{
    int i = 0;
    student *head = NULL;

    head = (student *)malloc(sizeof(student));
    memset(head, 0, sizeof(student));
    student *end = head;

    student *node = NULL;

    while (end != NULL)
    {
        node = (student *)malloc(sizeof(student));
        memset(node, 0, sizeof(student));
        printf("input name:>");
        scanf("%s", node->info.name);
        printf("input age:>");
        scanf("%d", &(node->info.age));
        printf("input score_Chinese:>");
        scanf("%f", &(node->info.score[0]));
        printf("input score_Math:>");
        scanf("%f", &(node->info.score[1]));
        printf("input score_English:>");
        scanf("%f", &(node->info.score[2]));
        getchar();
        end->next = node;
        end = end->next;
        i++;
        if (i!=0)
            break;
    }
    end->next = NULL;
    return head;
}
void output(student *head) // 输出学生信息
{
    if(head==NULL)
    {
        perror("NO info ! Please add info !\n");
        exit(-1);
    }
    printf("name\tage\tChinese\t  Math\t  English\n");
      head = head->next;
    while (head != NULL)
    {

        printf("%s\t%d\t  %.2f\t  %.2f\t  %.2f\n", head->info.name, head->info.age, head->info.score[0], head->info.score[1], head->info.score[2]);
        head = head->next;
    }
}

float max_score(student *end)
{
    float max=0;
    int i = 0;
    for (i = 0; i < 3;i++)
    {
        if(end->info.score[i]>max)
        {
            max = end->info.score[i];
        }
    }
        return max;
}

float seek_max_score(student *head, const char *name) // 统计查询
{
    if (head == NULL)
    {
        perror("NO info ! Please add info !\n");
        exit(1);
    }
    float max = 0;
    student *end = NULL;
    end = head->next;

    while (end != NULL)
    {
        if(!strcmp(end->info.name,name))
        {
            max = max_score(end);
        }
        end = end->next;
    }
    return max;
}
 
void insert_tail(student *head) // 尾插
{
    student *end = head;
    end = end->next;
    student *befor_end = NULL;
    student *new_info = NULL;
    new_info = (student *)malloc(sizeof(student));
    memset(new_info, 0, sizeof(student));
    printf("input insert name:>");
    scanf("%s", new_info->info.name);
    getchar();
    printf("input insert age:>");
    scanf("%d", &(new_info->info.age));
    printf("input inser Chinese score:>");
    scanf("%f", &(new_info->info.score[0]));
    printf("input inser Math score:>");
    scanf("%f", &(new_info->info.score[1]));
    printf("input inser English score:>");
    scanf("%f", &(new_info->info.score[2]));

    while(end!=NULL)
    {
        if(end->next==NULL)
        {
            befor_end = end;
        }
        end = end->next;
    }
    new_info->next = befor_end->next;
    befor_end->next = new_info;
    return head;
}

student *insert_node(student *head, const char *nam) // 中间插入
{
    if (head == NULL)
    {
        perror("NO info ! Please add info !\n");
        exit(1);
    }
    student *end = NULL;
    end = head->next;
    student *insert_node = NULL;
    while (end != NULL)
    {
        if (strcmp(nam, end->info.name))
        {
            insert_node = end;
            break;
        }
        end = end->next;
    }
    student *insert_info = (student *)malloc(sizeof(student));
    memset(insert_info, 0, sizeof(student));

    printf("input insert name:>");
    scanf("%s", insert_info->info.name);
    getchar();
    printf("input insert age:>");
    scanf("%d", &(insert_info->info.age));
    printf("input inser Chinese score:>");
    scanf("%f", &(insert_info->info.score[0]));
    printf("input inser Math score:>");
    scanf("%f", &(insert_info->info.score[1]));
    printf("input inser English score:>");
    scanf("%f", &(insert_info->info.score[2]));
    insert_info->next = insert_node->next;
    insert_node->next = insert_info;

    return head;
}

// 删除信息
void delete_node(student *head, const char *name) // 删除指定节点
{
    if (head == NULL)
    {
        perror("NO info ! Please add info !\n");
        exit(1);
    }
    student *end = head;

    student *delete_node = NULL;
    student *before_node = NULL;
    while (end != NULL)
    {
        before_node = end;
        end = end->next;
        if (!strcmp(name, end->info.name))
        {
            delete_node = end;
            break;
        }
    }
    if (delete_head != NULL)
    {
        before_node->next = delete_node->next;

        free(delete_node);
        delete_node = NULL;
    }
    else
    {
        printf("NO DELLET NAME!\n");
    }
    return head;
}

void revise_info(student *head,const char *name)   //修改内容
{
    if (head == NULL)
    {
        perror("NO info ! Please add info !\n");
        exit(1);
    }
    student *end = head;
    end = head->next;
    while(end!=NULL)
    {
        if(!strcmp(name,end->info.name))
        {
            printf("input revise name:>");
            scanf("%s", end->info.name);
            getchar();
            printf("input insert age:>");
            scanf("%d", &(end->info.age));
            printf("input inser Chinese score:>");
            scanf("%f", &(end->info.score[0]));
            printf("input inser Math score:>");
            scanf("%f", &(end->info.score[1]));
            printf("input inser English score:>");
            scanf("%f", &(end->info.score[2]));
        }
        end = end->next;
    }
    return head;
}

void list_free(student *head) // 释放链表
{
    student *end = head;
    while(head!=NULL)
    {
        end = head;
        head = end->next;
        free(end);
        end = NULL;
    }
}

void menu()
{
    printf("*******************************************************\n");
    printf("************Student Mcore Management System************\n");
    printf("*******************************************************\n");
    printf("********1.add info *************2.view info***********\n");
    printf("********3.delete info***********4.revise info*********\n");
    printf("********5.seek max score********0.exit****************\n");
    printf("*******************************************************\n");
}
#define _CRT_SECURE_NO_WARNINGS 1
#include "student.h"

stu *input_info(int n)
{
    int i = 0;
    stu *head = malloc(sizeof(stu));
    memset(head, 0, sizeof(head));
    stu *end = head;
    stu *node = NULL;

    while(end!=NULL)
    {
        node = malloc(sizeof(stu));
        memset(node, 0, sizeof(stu));
        printf("input name:>");
        scanf("%s", node->info.name);
        printf("input age:>");
        scanf("%d", &(node->info.age));
        printf("input score:>");
        scanf("%f", &(node->info.score));
        end->next = node;
        end = end->next;
        i++;
        if(i>=n)
            break;
    }
    end->next = NULL;
    return head;
}
void output_info(stu *head)
{
    stu *end = NULL;
    end = head->next;
    printf("name\tage\tscore\n");
    while(end!=NULL)
    {
        printf("%s\t%d\t%.2f\n", end->info.name, end->info.age, end->info.score);
        end = end->next;
    }
}

void free_list(stu *head)
{
    stu *end = head;
    while(head!=NULL)
    {
        end = head;
        head = head->next;
        free(end);
        end = NULL;
    }
}
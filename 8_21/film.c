//1、申请链表，存入目前比较热的五部电影（电影名称，豆瓣评分，上映时间）
//2、计算评分最高的电影名称
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    typedef struct film
{
    char name[20];
    float score;
    char time[20];
    struct film *next;
} FILM;

FILM *input_film(FILM *head,int n);
void output_score_max(FILM *head);

int main()
{
    FILM *head = NULL;
    head = input_film(head, 5);
    output_score_max(head);
    return 0;
}
FILM *input_film(FILM *head,int n)
{
    int i = 0;
    head = (FILM*)malloc(sizeof(FILM));
    bzero(head, sizeof(FILM));
    FILM *end = head;
    FILM *node = NULL;

    while(1)
    {
        node = (FILM*)malloc(sizeof(FILM));
        bzero(node, sizeof(FILM));
        printf("input film name:>");
        scanf("%s", node->name);
        printf("inout film score:>");
        scanf("%f", &(node->score));
        getchar();
        printf("input flim time:>");
        scanf("%s", node->time);
        getchar();
        end->next = node;
        end = end->next;
        i++;
        if(i>=n)
            break;
    }
    end->next = NULL;
    return head;
}
void output_score_max(FILM *head)
{
    float max = 0;
    int temp_score = 0;
    char temp[20] = {0};
    printf("  电影名\t豆瓣评分\t上映时间\n");
    while(head->next!=NULL)
    {
        head = head->next;
        printf("  %s\t\t%.2f\t\t%s\n",head->name,head->score,head->time);
        temp_score = (head->score) * 100;
        if (temp_score>= max)
        {
            max = temp_score;
            strcpy(temp, head->name);
        }
    }
   printf("评分最高的电影是 %s,评分 %.2f \n", temp, max/100);
}
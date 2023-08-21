//新建一个链表，包含若干个个元素，存储电影信息，然后显示所有内容。 
//设计一个函数，查询指定电影名字的信息，返回该节点的地址。 
//设计一个函数，查询票房最高的电影的信息。
//设计一个函数，下架评分最低电影信息 
//设计一个函数，查询 6 月份上映的所有电影的名字。 
//设计一个函数，在链表末尾插入一个电影信息节点。

#include "movie.h"

int main()
{
    FILM *head = NULL;
    FILM *seek_address=NULL;

    head = input_info(head, 3);
    printf_info(head);

    seek_address = seek_film(head);  
    printf("该电影的节点地址为:%p\n", seek_address);

    highest_ticket(head);//最高分电影信息

    head=delete_film(head);  //删除最低分电影
    printf_info(head);

    Seek_JUNE_Online(head); //查找6月上映的电影

    input_end(head);  //在尾端插入电影信息
    printf_info(head);

   
    free(seek_address);
    seek_address = NULL;

    return 0;
}

FILM* input_info(FILM *head,int n)
{
    int i = 0;
    head = (FILM *)malloc(sizeof(FILM));
    bzero(head, sizeof(FILM));
    FILM *end = head;
    FILM *node = NULL;
    while(1)
    {
        node = (FILM *)malloc(sizeof(FILM));
        bzero(node, sizeof(FILM));

        printf("input film name:>");
        scanf("%s", node->name);

        printf("input film ticket:>");
        scanf("%d", &(node->ticket));

        printf("input film dat:>");
        scanf("%d-%d-%d", &(node->dat.year),&(node->dat.mouth),&(node->dat.day));
        end->next = node;
        end = end->next;
        i++;
        if(i>=n)
            break;
    }
    end->next = NULL;
    return head;
}

void printf_info(FILM *head)
{
    printf("电影名\t\t评分\t\t上映时间\n");
    while(head->next!=NULL)
    {
        head = head->next;
        printf("%s\t\t%d\t\t%d-%d-%d\n", head->name, head->ticket, head->dat.year, head->dat.mouth, head->dat.day);
    }
}

FILM* seek_film(FILM *head)
{
    FILM *address = NULL;
    char seek_film[20] = {0};
    printf("请输入查找的电影名:>");
    scanf("%s", seek_film);
    while(head->next!=NULL)
    {
        head = head->next;
        if(!strcmp(seek_film,head->name))
        {
            printf("%p\n", head);
            address = head;
        }
    }
    return address;
}

void highest_ticket(FILM *head)
{
    
    int temp_ticket_max = 0;
    char temp_name[20] = {0};
    while (head->next != NULL)
    {
        head = head->next;
        if(head->ticket>temp_ticket_max)
        {
            temp_ticket_max = head->ticket;
            strcpy(temp_name,head->name);
        }
    }
    printf("评分最高的电影为:>%s,评分为:>%d\n", temp_name, temp_ticket_max);
}

FILM* delete_film(FILM *head)
{
    int temp_ticket_min = 0;
    FILM *end = head;
    FILM *before_delete_node = NULL;
    FILM *delete_node = NULL;
    FILM *temp = NULL;

    temp_ticket_min = head->next->ticket;

    while(end!=NULL)
    {       
        before_delete_node = end;
        end = end->next;
        if(end!=NULL&&end->ticket<=temp_ticket_min)
        {
            temp = before_delete_node;
            delete_node = end;
        }
        
    }
    if(delete_node!=NULL)
    {
        temp->next = delete_node->next;
        free(delete_node);
        delete_node = NULL;
    }
    return head;
}

void Seek_JUNE_Online(FILM *head)
{
    FILM *end = head;
    printf("六月上映的电影有:>");
    while(end!=NULL)
    {
        end=end->next;
        if(end!=NULL&&end->dat.mouth==6)
        {
            printf("%s\t", end->name);
        }
    }
    printf("\n");
}

FILM* input_end(FILM *head)
{
    FILM *end = head;
    end = end->next;
    FILM *befor_end = NULL;
    FILM *new_info = NULL;
    new_info = (FILM *)malloc(sizeof(FILM));
    bzero(new_info, sizeof(FILM));
    strcpy(new_info->name,"霸王别姬");
    new_info->ticket = 96;
    new_info->dat.year=1993;
    new_info->dat.mouth = 7;
    new_info->dat.day = 26;

    //  new_info->next = NULL;

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

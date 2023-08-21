/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: link.c
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月21日 星期一 10时48分30秒
***************************************************/

#include "link.h"

int main(int argc,const char* argv[])
{
	INFO *head = NULL;
	head = input_info(head,4);
	output_info(head);

	head = increase_info(head, 3);
	output_info(head);

	head = delete_info(head, 5);
	output_info(head);

	free_all_node(head);

	return 0;
}

INFO* input_info(INFO *head,int n)  //链表输入函数
{
	int i = 0;
	head=(INFO*)malloc(sizeof(INFO));
	bzero(head,sizeof(INFO));
	INFO *end=head;
	INFO *node=NULL;
	while(1)
	{
		node = (INFO*)malloc(sizeof(INFO));
		bzero(node,sizeof(INFO));
		printf("input id:>");
		scanf("%d",&(node->id));
		printf("input name:>");
		scanf("%s",node->name);
		end->next = node;
		end = end->next;
		i++;
		if(i>=n)
			break;
	}

	end = NULL;
	return head;
}

void output_info(INFO *head)  //链表打印函数
{
	while(head->next!=NULL)
	{
		head=head->next;
		printf("id:%d\tname:%s\n",head->id,head->name);
	}
	
}

INFO* increase_info(INFO *head,int iid)  //插入
{
	INFO *end = head;
	end = end->next;
	INFO *increase_node = NULL;
	while (end!= NULL)
	{
		if(end->id==iid)
		{
			increase_node = end;
			break;			
		}
		end = end->next;
	}
	INFO *new_info = (INFO *)malloc(sizeof(INFO));
	new_info->id = 5;
	strcpy(new_info->name, "hello");
	new_info->next= increase_node->next;
	increase_node->next = new_info;
	return head;
}

INFO* delete_info(INFO *head,int iid)  //删除
{
	INFO *end = head;
	INFO *delete_node = NULL;
	INFO *befor_node = NULL;
	while (end != NULL)
	{
		befor_node = end;
		end = end->next;
		if (end->id == iid)
		{
			delete_node = end; 
			break;
		}
	}
		if (delete_node != NULL)
		{
			befor_node->next = end->next;
			free(delete_node);
			delete_node = NULL;
		}
		else
		{
			printf("NO DELETE NODE!\n");
		}
		return head;	
}
void free_all_node(INFO *head)
{
		INFO *end = NULL;
		while(head!=NULL)
		{
			end = head;
			head = end->next;
			free(end);
			end = NULL;
		}
}
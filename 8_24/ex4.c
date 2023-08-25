/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: ex4.c
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月24日 星期四 17时26分54秒
***************************************************/

//用链表存储多个学员信息，将其保存为文本文件。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct student
{
	char name[20];
	int age;
	float score;
};

typedef struct node
{
	struct student info;
	struct node *next;
}stu;
stu *input_info(void);
void free_list(stu *head);

int main(int argc,const char* argv[])
{
	stu *head = NULL;
	head = input_info();	
	stu *end = head;
	end = end->next;
	FILE *fp = NULL;
	fp=fopen("./info3.txt","r+");
	fprintf(fp,"name\tage\tscore\n");
	while(end!=NULL)
	{
		fprintf(fp,"%s\t%d\t%.2f\n",end->info.name,end->info.age,end->info.score);
		end = end->next;
	}

	free_list(head);
	fclose(fp);
   	return 0;
}

stu *input_info(void)
{
	int i = 0;
	stu *head = NULL;
	head = (stu*)malloc(sizeof(stu));
	memset(head,0,sizeof(stu));

	stu *end = head;
	stu *node = head;
	while(end!=NULL)
	{
		node = (stu*)malloc(sizeof(stu));
		memset(node,0,sizeof(stu));
		printf("input name:>");
		scanf("%s",node->info.name);
		printf("input age:>");
		scanf("%d",&(node->info.age));
		printf("input score:>");
		scanf("%f",&(node->info.score));
		end ->next = node;
		end = end->next;
		i++;
		if(i>2)
			break;
	}
	end->next = NULL;
	return head;
}

void free_list(stu *head)
{
	stu *end = head;
	while(head!=NULL)
	{
		end = head;
		head = head->next;
		free(end);
		end =NULL;
	}
	
}


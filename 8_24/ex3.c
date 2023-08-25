/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: ex3.c
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月24日 星期四 17时14分11秒
***************************************************/

//设计结构体存放学员信息，通过键盘输入一个将学员信息保存为文本文件。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	char name[10];
	int age;	
}stu;

int main(int argc,const char* argv[])
{
	stu *head = NULL;
	head = (stu*)malloc(sizeof(stu));
	memset(head,0,sizeof(stu));

	printf("input name:>");
	scanf("%s",head->name);
	printf("input age:>");
	scanf("%d",&(head->age));
	
	FILE *fp = NULL;
	
	fp = fopen("./info2.txt","r+");

	fprintf(fp,"name\tage\n");
	fprintf(fp,"%s\t%d\n",head->name,head->age);

	free(head);

	fclose(fp);

    return 0;
}

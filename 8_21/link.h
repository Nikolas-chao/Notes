/***************************************************
> Copyright (C) 2023 ==KINGYI== All rights reserved.
> File Name: link.h
> Author:qwe
> Mail:niechao5663@163.com 
> Created Time: 2023年08月21日 星期一 10时48分42秒
***************************************************/

#ifndef _LINK_H_
#define _LINK_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct info
{
	int id;
	char name[20];
	struct info *next;
}INFO;

INFO* input_info(INFO *head,int n);
void output_info(INFO *head);
INFO *increase_info(INFO *head, int iid);//链表增加
INFO *delete_info(INFO *head, int iid);	 // 链表删除
void free_all_node(INFO *head);			 // 释放所有节点
#endif

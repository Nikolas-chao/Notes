#ifndef USER_H
#define USER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sys_log.h"

typedef struct user
{
    char name[10];
    char password[10];
}INFO;

typedef struct Node
{
    INFO info;
   struct Node *next;
}USER;

USER *read_file_user();  //文件读取

void write_file_user(USER *head);  //文件写入

USER *input_user(USER *head);   //新建会员

void output_user(USER *head);   //查看商品

void add_user(USER *head); //添加会员

void seek_user(USER *head); //查找会员

void del_user(USER *head);  //删除会员

void change_passwprd(USER *head);  //修改密码

void free_user(USER *head);  //释放链表

#endif

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct student
{
    char name[10];
    int age;
    float score[3];
};

typedef struct node
{
    struct student info;
    struct node *next;
}student;

student *create_list(void);//新建学生信息
void output(student *head);//输出学生信息
float seek_max_score(student *head, const char *name); // 统计查询
 //插入信息
void insert_head(student *head, const char *name, int age, float score);    // 头插
void insert_tail(student *head);    // 尾插
student *insert_node(student *head, const char *nam); // 中间插入

void revise_info(student *head,const char *name);
// 删除信息
void delete_node(student *head, const char *name); // 删除指定节点
void delete_head(student *head);                   // 删除头节点
void delete_tail(student *head);                   // 删除尾节点
void list_free(student *head);                     // 释放链表

void revise_node(student *head, const char *name, int age, float score);//修改信息

void menu();

float max_score(student *head); // 找成绩最大值
#endif
#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[10];
    int age;
    float score;
}INFO;

typedef struct node
{
    INFO info;
    struct node *next;
} stu;

stu *input_info(int n);
void output_info(stu *head);
void free_list(stu *head);

#endif
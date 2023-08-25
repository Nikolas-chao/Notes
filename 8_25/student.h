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


#endif
#ifndef PRODUCT_H
#define PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct date
{
    int year;
    int mouth;
    int day;
}DATE;

typedef struct commodity
{
    char name[50];   //商品名称
    float price;   //商品价格
    float vip_price;  //会员价格
    DATE dat;         // 生产日期
    int quantity;    //商品数量
} Product_info;

typedef struct node
{
    Product_info info;
    struct node *next;
} Product;

Product *read_file(); // 文件读取

void write_file(Product *head); //文件写入

Product *input_info(Product *head); // 新建商品

void output_info(Product *head); // 查看商品

void input_info_end(Product *head); // 添加商品

void seek_product(Product *head); // 查找商品

void del_product(Product *head); // 删除商品

void change_product(Product *head); // 修改商品

void free_list(Product *head);                       // 释放链表
#endif
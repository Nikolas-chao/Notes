#ifndef CASHIE_H
#define CASHIE_H

#include "Product.h"
#include "menu.h"
#include "commodity_management.h"
#include "sys_log.h"

void Cashie();

Product *input_shop();//添加商品

void input_shop_end(Product *head); // 添加商品

void output_shop(Product *shop,Product *head); // 查看订单

void free_shop(Product *shop);//释放链表

float Payment(Product *head); //结账

float Payment1(Product *shop, Product *head);  //非会员结账

float Payment2(Product *shop, Product *head); //会员结账

int is_vip(USER *head, const char *name);   //是否为会员

void Pay(Product *shop);  //收银

void printf_shop(Product *shop, Product *head,float pay);//打印小票

#endif
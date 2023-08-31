#ifndef CASHIE_H
#define CASHIE_H

#include "Product.h"
#include "menu.h"
#include "commodity_management.h"

void Cashie();

Product *input_shop();//添加商品

void input_shop_end(Product *head); // 添加商品

void output_shop(Product *head); // 查看订单

void free_shop(Product *shop);//释放链表

float Payment(Product *head); //结账

#endif
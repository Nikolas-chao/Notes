#ifndef MENU_H
#define MENU_H

#include <stdio.h>
#include <time.h>

void get_localtime(); //获取当前时间

void menu_begin();// 初始界面

void menu_login_user();     // 管理员登录界面

void menu_Administrator();  // 管理员界面

void menu_Cashie(); // 收银员界面

void menu_commodity_management(); // 商品管理

void menu_Membership_management(); // 会员管理

void menu_vip();//

#endif
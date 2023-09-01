#include "menu.h"

void get_localtime() // 获取当前时间
{
    char *wday[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    time_t tim;
    struct tm *p;
    time(&tim);
    p = localtime(&tim);
    printf("当前时间为：%d年%d月%d日 ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    printf("%s %d时%d分%d秒\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
}

void menu_begin() // 初始界面
{
    printf("*******************************************\n");
    printf("***************便利店管理系统**************\n");
    printf("*******************************************\n");
    printf("***********1.管理信息*******2.收银*********\n");
    printf("*******************0.退出******************\n");
    printf("*******************************************\n");
    get_localtime();
}
void menu_login_user() // 管理员登录界面
{
    printf("*******************************************\n");
    printf("*****************管理员登录****************\n");
    printf("*******************************************\n");
    printf("**********1.登录***********0.退出**********\n");
    printf("*******************************************\n");
    get_localtime();
}
void menu_Administrator() // 管理员界面
{
    printf("*******************************************\n");
    printf("*******************管理员******************\n");
    printf("*******************************************\n");
    printf("**********1.全部商品*******2.商品管理******\n");
    printf("**********3.会员管理*******0.退出**********\n");
    printf("*******************************************\n");
    get_localtime();
}
void menu_Cashie()  //收银员界面
{
    printf("*******************************************\n");
    printf("*******************收银********************\n");
    printf("*******************************************\n");
    printf("**********1.全部商品*******2.选择商品******\n");
    printf("**********3.查看订单*******4.结账**********\n");
    printf("**********0.退出***************************\n");
    printf("*******************************************\n");
    get_localtime();
}
void menu_commodity_management() // 商品管理
{
    printf("*******************************************\n");
    printf("******************商品管理*****************\n");
    printf("*******************************************\n");
    printf("*********1.全部商品*****2.查找商品*********\n");
    printf("*********3.添加商品*****4.删除商品*********\n");
    printf("*********5.修改商品*****0.退出*************\n");
    printf("*******************************************\n");
    get_localtime();
}
void menu_Membership_management() // 会员管理
{
    printf("*******************************************\n");
    printf("******************会员管理*****************\n");
    printf("*******************************************\n");
    printf("*********1.全部会员*****2.查找会员*********\n");
    printf("*********3.添加会员*****4.注销会员*********\n");
    printf("*********5.修改密码*****0.退出*************\n");
    printf("*******************************************\n");
    get_localtime();
}
void menu_vip()
{
    printf("*******************************************\n");
    printf("******************是否为会员***************\n");
    printf("*******************************************\n");
    printf("*********1.是*****2.否****0.退出********\n");
    printf("*******************************************\n");
    get_localtime();
}
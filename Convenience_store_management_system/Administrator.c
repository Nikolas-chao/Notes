#include "Administrator.h"
#include "user.h"
#include "menu.h"

void login()
{
    int input = 0;
    do
    {
        menu_login_user();
        printf("请输入你的选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            login_Adm();
            break;
        case 0:
            printf("退出成功!\n");
            break;
        default:
            break;
        }
    } while (input);
    
}
void login_Adm()
{
    int i = 0;
    int j = 0;
    char arr[10] = {0};
    FILE *fp = NULL;
    int ret = 0;
    fp = fopen("./login.dat", "r");
    if (fp == NULL)
    {
        perror("fopen");
        exit(-1);
    }
    INFO *node = malloc(sizeof(INFO));
    memset(node, 0, sizeof(INFO));
    ret = fread(node, sizeof(INFO), 1, fp);
    if (ret != 1)
    {
        perror("fread");
    }
    fclose(fp);
    
    for (i = 0; i < 3;i++)
    {
        printf("请输入管理员用户名:>");
        scanf("%s", arr);
        if(strcmp(arr,node->name))
        {
            printf("用户名错误!请重新输入!\n");
        }
        else
        {
            for (j = 0; j < 3; j++)
            {
                printf("用户名正确,请输入密码:>");
                scanf("%s", arr);
                if (strcmp(arr, node->password))
                {
                    printf("密码输入错误!请重新输入!\n");
                  //  i = i + 1;
                }
                else 
                {
                    printf("登陆成功!\n");
                    Administrator();
                    i = 3;
                    break;
                }             
            }
            if (j >= 2)
            {
                printf("密码输错3次,请重新登录或退出!\n");
                break;
            }
        }
       
         if(i==2)
        {
            printf("用户名输错3次,请重新登录或退出!\n");
            break;
        }
    }
   
}

void Administrator()
{
    int input = 0;
    
    do
    {
        menu_Administrator();
        printf("输入你的选择:>");
        scanf("%d", &input);
    switch (input)
    {
        case 1:
            printf_Product();  // 查看全部商品
            break;
        case 2:
            commodity_management(); // 商品管理
            break;
        case 3:
            Membership_management(); // 会员管理
            break;
        case 0:
            printf("退出成功!\n");
            break;
        default:
            printf("选项无效,请重新选择!\n");
            break;
        }
    } while (input);
}
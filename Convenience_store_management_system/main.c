#include "menu.h"
#include "Product.h"
#include "commodity_management.h"
#include "Administrator.h"
#include "Cashie.h"
#include "sys_log.h"

int main()
{
    int input = 0;
    errno = 0;
    do
    {
        menu_begin();
        printf("输入你的选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            login(); // 管理员
            break;
        case 2:
            Cashie(); // 收银员
            break;
        case 0:
            printf("退出成功!\n");
            printf_log(__FUNCTION__, __FILE__, __LINE__);
            break;
        default:
            printf("选择无效,请重新选择!\n");
            break;
        }
    } while (input);
    return 0;
}

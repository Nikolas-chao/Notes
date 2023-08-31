#include "commodity_management.h"

void printf_Product(void)// 查看全部商品
{
    Product *head = NULL;
    head = read_file();
    output_info(head);
}

void commodity_management(void) // 商品管理
{
    int input = 0;
    Product *head = NULL;
    head=read_file();
    do
    {
        menu_commodity_management();
        printf("input:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            output_info(head);
            break;
        case 2:
            seek_product(head);
            break;
        case 3:
            if (head->next == NULL)
            {
                head = input_info(head);
            }
            else
            {
                input_info_end(head);
            }
            break;
        case 4:
            del_product(head);
            break;
        case 5:
            change_product(head);
            break;
        case 0:
            write_file(head);
            free_list(head);

            printf("退出成功!\n");
            break;
        default:
            printf("no\n");
            break;
        }
    } while (input);
}

void Membership_management(void) // 会员管理
{
    int input = 0;
    USER *head = NULL;
    head = read_file_user();
    do
    {
        menu_Membership_management();
        printf("input:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            output_user(head);
            break;
        case 2:
            seek_user(head);
            break;
        case 3:
            if(head->next==NULL)
            {
                head = input_user(head);
            }
            else
            {
                add_user(head);
            }
            break;
        case 4:
            del_user(head);
            break;
        case 5:
            change_passwprd(head);
            break;
        case 0:
            write_file_user(head);
            free_user(head);
            printf("退出成功!\n");
            break;
        default:
            break;
        }
    } while (input);
    
}

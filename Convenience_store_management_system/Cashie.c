#include "Cashie.h"

void Cashie()
{
    int input = 0;
    float pay = 0;
    Product *head = NULL;
    head = read_file();
    USER *name = NULL;
    name = read_file_user();
    Product *shop = NULL;

    do
    {
        menu_Cashie();
        printf("请输入你的选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf_Product(); // 全部商品
            break;
        case 2:
            if (shop == NULL)
            {
                shop = input_shop(); // 选择商品
            }
            else
            {
                input_shop_end(shop);
            }
            break;
        case 3:
            output_shop(shop, head); // 查看订单
            break;
        case 4:
            Pay(shop);
            break;
        case 0:
            free_shop(shop);
            printf("退出成功!\n");
            break;
        default:
            printf("选择无效,请重新选择!\n");
            break;
        }
    } while (input);
}

Product *input_shop() // 新建商品
{
    Product *head = NULL;
    head = malloc(sizeof(Product));
    memset(head, 0, sizeof(Product));
    Product *end = head;
    Product *node = NULL;
    while (end != NULL)
    {
        node = malloc(sizeof(Product));
        memset(node, 0, sizeof(Product));
        printf("请输入商品名称:>");
        scanf("%s", node->info.name);
        if (!strcmp(node->info.name, "0"))
            break;
        end->next = node;
        end = end->next;
    }
    end = NULL;
    return head;
}
void input_shop_end(Product *head) // 添加商品
{
    Product *end = head;
    end = end->next;
    Product *bef_end = NULL;
    Product *node = NULL;
    node = malloc(sizeof(Product));
    memset(node, 0, sizeof(Product));
    printf("请输入商品名称:>");
    scanf("%s", node->info.name);
    while (end != NULL)
    {
        if (end->next == NULL)
        {
            bef_end = end;
        }
        end = end->next;
    }
    bef_end->next = node;
    node->next = NULL;
}
void output_shop(Product *shop, Product *head)
{
    if (shop == NULL)
    {
        printf("订单为空,请添加商品!\n");
        exit(-1);
    }
    Product *end = head;
    end = head->next;
    Product *node = shop;
    node = node->next;
    printf("商品名\t\t价格\n");
    while (node != NULL)
    {
        while (!strcmp(node->info.name, end->info.name))
        {
            printf("%s\t%.2f\n", node->info.name, end->info.price);
            node = node->next;
            if (node == NULL)
            {
                break;
            }
            end = head->next;
        }
        end = end->next;
    }
}

void free_shop(Product *head)
{
    Product *end = head;
    while (head != NULL)
    {
        end = head;
        head = head->next;
        free(end);
        end = NULL;
    }
}

float Payment1(Product *shop, Product *head)
{
    float temp = 0;
    Product *end = head;
    end = head->next;
    Product *node = shop;
    node = node->next;
    while (node != NULL)
    {
        while (!strcmp(node->info.name, end->info.name))
        {
            temp = temp + end->info.price;
            node = node->next;
            if (node == NULL)
            {
                break;
            }
            end = head->next;
        }

        end = end->next;
    }
    return temp;
}

float Payment2(Product *shop, Product *head)
{
    float temp = 0;
    Product *end = head;
    end = head->next;
    Product *node = shop;
    node = node->next;
    while (node != NULL)
    {
        while (!strcmp(node->info.name, end->info.name))
        {
            temp = temp + end->info.vip_price;
            node = node->next;
            if (node == NULL)
            {
                break;
            }
            end = head->next;
        }

        end = end->next;
    }
    return temp;
}

int is_vip(USER *head, const char *name)
{
    USER *end = head;
    end = head->next;

    while (end != NULL)
    {
        if (!strcmp(end->info.name, name))
        {
            return 1;
        }
        end = end->next;
    }
}

void Pay(Product *shop)
{
    int input = 0;
    float pay = 0;
    Product *head = NULL;
    head = read_file();
    USER *user = NULL;
    user = read_file_user();

    char name[10] = {0};
    int flag = 0;
    do
    {
        menu_vip();
        printf("请输入你的选择:>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:
            printf("请输入你的会员名:>");
            scanf("%s", name);
            flag = is_vip(user, name);
            if (flag == 1)
            {
                pay = Payment2(shop, head);
                printf("应支付%.2f元\n", pay);
            }
            else
            {
                pay = Payment1(shop, head);
                printf("你不是会员,应支付%.2f元\n", pay);
            }
            break;
        case 2:
            pay = Payment1(shop, head);
            printf("应支付%.2f元\n", pay);
            break;
        case 0:
            printf("您的小票为:>\n");
            printf_shop(shop, head, pay);
            get_localtime();
            printf("退出成功!\n");
            break;
        default:
            break;
        }

    } while (input);
}

void printf_shop(Product *shop, Product *head, float pay)
{
    Product *end = head;
    end = head->next;
    Product *node = shop;
    node = node->next;
    printf("商品名\t\t价格\t会员价格\n");
    while (node != NULL)
    {
        while (!strcmp(node->info.name, end->info.name))
        {
            printf("%s\t%.2f\t%.2f\n", node->info.name, end->info.price, end->info.vip_price);
            node = node->next;
            if (node == NULL)
            {
                break;
            }
            end = head->next;
        }
        end = end->next;
    }
    printf("合计：%.2f元\n", pay);
}
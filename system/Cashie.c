#include "Cashie.h"

void Cashie()
{
    int input = 0;
    float pay = 0;
    Product *head = NULL;
    head = read_file();
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
                if(shop==NULL)
               { 
                    shop = input_shop(); // 选择商品 
               }
                else
               {
                    input_shop_end(shop);
               }                          
                break;
            case 3:
                output_shop(shop); // 查看订单
                break;
            case 4:
                pay=Payment(shop);   // 结账
                printf("您需要付款%.2f元\n", pay);
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

Product *input_shop()  //新建商品
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
        if(!strcmp(node->info.name,"0"))
            break;
        printf("请输入价格:>");
        scanf("%f", &(node->info.price));
        end->next = node;
        end = end->next;
    }
    end = NULL;
    return head;
}
void input_shop_end(Product *head)  //添加商品
{
    Product *end = head;
    end = end->next;
    Product *bef_end = NULL;
    Product *node = NULL;
    node = malloc(sizeof(Product));
    memset(node, 0, sizeof(Product));
    printf("请输入商品名称:>");
    scanf("%s", node->info.name);
    printf("请输入价格:>");
    scanf("%f", &(node->info.price));
    while (end!= NULL)
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
void output_shop(Product *head)
{
    if(head==NULL)
    {
        perror("订单为空,请添加商品!\n");
        exit(-1);
    }

    Product *end = head;
    end = end->next;
    printf("商品名\t\t价格\n");
    while(end!=NULL)
    {
        printf("%s\t%.2f\n", end->info.name, end->info.price);
        end = end->next;
    }
}

void free_shop(Product *head)
{
    Product *end = head;
    while (head!=NULL)
    {
        end = head;
        head = head->next;
        free(end);
        end = NULL;
    }   
}

float Payment(Product *head)
{
    float temp = 0;
    Product *end = head;
    end = head->next;
    while(end!=NULL)
    {
        temp = temp + end->info.price;
        end = end->next;
    }
    return temp;
}

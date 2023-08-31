#include "Product.h"

Product *read_file() // 读取文件
{
    FILE *fp = NULL;
    char ch = 0;
    int ret = 0;

    Product *head = NULL;
    head = malloc(sizeof(Product));
    memset(head, 0, sizeof(Product));
    Product *end = head;
    Product *node = NULL;

    fp = fopen("./Product.dat", "r");
    if (fp == NULL)
    {
        printf_log(__FUNCTION__, __FILE__, __LINE__);
        exit(-1);
    }
    ch = fgetc(fp);
    rewind(fp);
    while (ch != EOF)
    {
        node = malloc(sizeof(Product));
        memset(node, 0, sizeof(Product));
        ret = fread(node, sizeof(Product_info), 1, fp);
        if (ret != 1)
        {
            printf_log(__FUNCTION__, __FILE__, __LINE__);
        }
        //   printf("%s\t%.2f\t%.2f\t%d-%d-%d\t%d\n", node->info.name, node->info.price, node->info.vip_price, node->info.dat.year, node->info.dat.mouth, node->info.dat.day, node->info.quantity);     //查看读取到的内容
        end->next = node;
        end = end->next;
        ch = fgetc(fp);
        fseek(fp, -1, SEEK_CUR);
    }
    fclose(fp);
    return head;
}

void write_file(Product *head)
{
    FILE *fp = NULL;
    FILE *fp_txt = NULL;
    fp = fopen("./Product.dat", "w");
    fp_txt = fopen("./Product.txt", "w");

    Product *end = head;
    end = end->next;
    int set = 0;

    fprintf(fp_txt, "商品名称\t商品价格\t会员价格\t生产日期\t库存数量\n");

    while (end != NULL)
    {
        set = fwrite(end, sizeof(Product_info), 1, fp);
        if (set != 1)
        {
            printf_log(__FUNCTION__, __FILE__, __LINE__);
        }
        fprintf(fp_txt, "%s\t  %.2f\t\t %.2f\t  %d-%d-%d\t\t%d\n", 
        end->info.name, end->info.price, end->info.vip_price, 
        end->info.dat.year, end->info.dat.mouth, end->info.dat.day, end->info.quantity);
        end = end->next;
    }
    fclose(fp);
    fclose(fp_txt);
}

Product *input_info(Product *head) // 新建商品
{
    Product *end = head;
    int i = 0;
    Product *node = NULL;

    while (end != NULL)
    {
        node = malloc(sizeof(Product));
        memset(node, 0, sizeof(Product));
        printf("请输入商品名字:>");
        scanf("%s", node->info.name);
        printf("请输入商品价格:>");
        scanf("%f", &(node->info.price));
        printf("请输入会员价格:>");
        scanf("%f", &(node->info.vip_price));
        printf("请输入上产日期:>");
        scanf("%d-%d-%d", &(node->info.dat.year), &(node->info.dat.mouth), &(node->info.dat.day));
        printf("请输入商品数量:>");
        scanf("%d", &(node->info.quantity));
        end->next = node;
        end = end->next;
        i++;
        if (i != 0)
            break;
    }
    end = NULL;
    return head;
}
void input_info_end(Product *head) // 添加商品
{
    Product *end = head;
    end = end->next;
    Product *bef_end = NULL;

    Product *node = NULL;
    node = malloc(sizeof(Product));
    memset(node, 0, sizeof(Product));
    printf("请输入商品名字:>");
    scanf("%s", node->info.name);
    printf("请输入商品价格:>");
    scanf("%f", &(node->info.price));
    printf("请输入会员价格:>");
    scanf("%f", &(node->info.vip_price));
    printf("请输入上产日期:>");
    scanf("%d-%d-%d", &(node->info.dat.year), &(node->info.dat.mouth), &(node->info.dat.day));
    printf("请输入商品数量:>");
    scanf("%d", &(node->info.quantity));

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

void output_info(Product *head) // 查看商品
{
    if (head == NULL)
    {
        perror("没有商品信息,请添加!\n");
        exit(-1);
    }
    Product *end = NULL;
    end = head->next;

    printf("商品名\t  价格\t会员价\t生产日期\t库存\n");
    while (end != NULL)
    {
        printf("%s  %.2f\t%.2f\t%d-%d-%d\t%d\n", end->info.name, end->info.price, end->info.vip_price, end->info.dat.year, end->info.dat.mouth, end->info.dat.day, end->info.quantity);
        end = end->next;
    }
}

void seek_product(Product *head) // 查找商品
{
    if (head == NULL)
    {
        perror("没有商品信息,请添加!\n");
        exit(-1);
    }
    char name[20] = {0};
    printf("输入查找的商品名称:>");
    scanf("%s", name);
    Product *end = NULL;
    end = head->next;
    Product *node = NULL;
    while (end != NULL)
    {
        if (!strcmp(end->info.name, name))
        {
            node = end;
            break;
        }
        end = end->next;
    }
    if (node == NULL)
    {
        perror("no\n");
        exit(-1);
    }
    else
    {
        printf("%s\t%.2f\t%.2f\t%d-%d-%d\t%d\n", node->info.name, node->info.price, node->info.vip_price, node->info.dat.year, node->info.dat.mouth, node->info.dat.day, node->info.quantity);
    }
}

void del_product(Product *head) // 删除商品
{
    if (head == NULL)
    {
        perror("没有商品信息,请添加!\n");
        exit(-1);
    }
    char name[20] = {0};
    printf("输入删除的商品名称:>");
    scanf("%s", name);
    Product *end = head;
    Product *bef_node = NULL;
    Product *node = NULL;
    //  end = head->next;
    while (end != NULL)
    {
        bef_node = end;
        end = end->next;
        if (!strcmp(end->info.name, name))
        {
            node = end;
            break;
        }
    }
    if (node == NULL)
    {
        printf("no this node!\n");
    }
    else
    {
        bef_node->next = node->next;
    }
}
void change_product(Product *head) // 修改商品
{
    if (head == NULL)
    {
        perror("没有商品信息,请添加!\n");
        exit(-1);
    }
    char name[20] = {0};
    printf("输入修改的商品名称:>");
    scanf("%s", name);
    Product *end = head;
    end = end->next;
    while (end != NULL)
    {
        if (!strcmp(end->info.name, name))
        {
            printf("请输入修改后的信息:\n");
            printf("请输入商品名字:>");
            scanf("%s", end->info.name);
            printf("请输入商品价格:>");
            scanf("%f", &(end->info.price));
            printf("请输入会员价格:>");
            scanf("%f", &(end->info.vip_price));
            printf("请输入上产日期:>");
            scanf("%d-%d-%d", &(end->info.dat.year), 
            &(end->info.dat.mouth), &(end->info.dat.day));
            printf("请输入商品数量:>");
            scanf("%d", &(end->info.quantity));
        }
        end = end->next;
    }
}
void free_list(Product *head) // 释放链表
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
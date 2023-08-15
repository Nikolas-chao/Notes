//支付钱数
#include <stdio.h>

int main()
{
    int pay_money = 0;
    int money_hunder = 0;
    int money_fifty = 0;
    int money_ten = 0;
    int money_five = 0;
    int money_one = 0;

    printf("input pay_money:> ");
    scanf("%d", &pay_money);
    printf("\n");
    if(pay_money/100!=0)
    {
        money_hunder = pay_money / 100;
        pay_money = pay_money - money_hunder * 100;
    }
    if (pay_money / 50 != 0)
    {
        money_fifty = pay_money / 50;
        pay_money = pay_money - money_fifty * 50;
    }
    if (pay_money / 10 != 0)
    {
        money_ten = pay_money / 10;
        pay_money = pay_money - money_ten * 10;
    }
    if (pay_money / 5 != 0)
    {
        money_five = pay_money / 5;
        pay_money = pay_money - money_five * 5;
    }
    if (pay_money / 1 != 0)
    {
        money_one = pay_money / 1;
        pay_money = pay_money - money_one * 1;
    }
    printf("应支付%d张100元,%d张50元,%d张10元,%d张5元,%d张1元\n", money_hunder, money_fifty, money_ten, money_five, money_one);

    return 0;
}
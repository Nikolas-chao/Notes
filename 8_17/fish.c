// 打鱼还是晒网
//某人从2000年1月1日开始“三天打鱼两天晒网”，任意输入某一天，判断这一天是打鱼还是晒网 * /
//    考虑：瑞年，平年 – 2月 不考虑天气，假期，等客观因素

#include <stdio.h>

typedef struct time
{
    int year;
    int month;
    int day;
}DATE;
int total_day(DATE);
int Leap_year(int year);  //判断闰年
int main()
{
    DATE days;
    int count_day = 0;
    int output = 0;
    printf("请输入指定的日期（如：xxxx年，x月，x日）:>");
    scanf("%d,%d,%d", &days.year,&days.month,&days.day);

    count_day = total_day(days);

    output = count_day % 5;  //余数为1，2，3为出去打渔
    if(output>0&&output<4)
    {
        printf("%d年%d月%d日,出去打渔\n", days.year, days.month, days.day);
    }
    else
    {
        printf("%d年%d月%d日,在家晒网\n", days.year, days.month, days.day);
    }


    return 0;
}
int Leap_year(int year)
{
    if((year%4==0&&year%100==0)||(year%400==0))
        return 1;
    else
        return 0;
}
int total_day(DATE days)
{
    int MOUTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int countday = 0;
    int year = 0;
    int i = 0;
    for (year = 2000;year<=days.year;year++)
    {
        if(Leap_year(year))
            countday=countday+366;
        else
            countday = countday + 365;
    }
    if(Leap_year(days.year))
        MOUTH[2] += 1;
    for (i = 0; i < days.month;i++)
    {
        countday += MOUTH[i];
    }
    countday += days.day;
    return countday;
}
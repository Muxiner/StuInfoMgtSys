#include <stdio.h>
#include <stdlib.h>
//仅仅是计算一年中1.1到该日期的天数
int main(void)
{
    //输入日期
    int year, month, day;
    printf("Please input the date:(2020 4 14)\n=>");
    scanf("%d %d %d", &year, &month, &day);

    //每个月中的天数
    int mDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //判断闰年,二月份天使为29
    if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
    mDays[2] += 1;

    int days = 0;
    days += day;

    for (int i = 0; i < month; i++)
    days += mDays[i];

    //打印天数
    printf("%d %d %d is the %d day in the %d\n", year, month, day, days, year);
    system("pause");
    return 0;
}
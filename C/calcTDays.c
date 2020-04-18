#include <stdio.h>
#include <stdlib.h>

// 计算两个日期间的天数

struct Date
{
    int year;
    int month;
    int day;
};


void inputDay(struct Date *dateO,struct Date *dateT)
{
    //输入两个日期
    printf("Please input a date(e.g:2019 11 2):");
    scanf("%d %d %d", &dateO->year, &dateO->month, &dateO->day);
    printf("Please input another date(e.g:2020 4 14):");
    scanf("%d %d %d", &dateT->year, &dateT->month, &dateT->day);
}
int isLeap(struct Date *date)
{
     if ((date->year % 4 == 0) && ((date->year % 100 != 0) || (date->year % 400 == 0)))
       return 1;
       else return 0;
}

int calcDays(struct Date *date, int mDays[])
{
    int days = 0;
    days += date->day;
    for (int i = 0; i < date->month; i++)
    {
        days += mDays[i];
        //闰年二月是29天
        if ((isLeap(date)) && i == 2)
        days += 1;
    }
    return days;
}

int daysInyear(int year)
{
     if ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)))
    return 366;
    else return 365;
}

int main()
{
    struct Date dateO;
    struct Date dateT;
    
    inputDay(&dateO, &dateT);

    //每个月的天数（平年）
    int mDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //计算天数
    int days = 0;
    if (dateT.year - dateO.year == 0)
    {
        days = calcDays(&dateT, mDays) - calcDays(&dateO, mDays); 
    }
    else if(dateT.year - dateO.year > 0)
    {
       for (int i = dateO.year; i < dateT.year; i++)
       {
          days += daysInyear(i); 
       }

       days = days - calcDays(&dateO, mDays) + calcDays(&dateT, mDays); 
    }
    else 
    {
        printf("Input error!!!\n");
        system("pause");
        return 0;
    }

    printf("The number of days between (%d %d %d) and (%d %d %d) is %d\n",
     dateO.year, dateO.month, dateO.day,dateT.year, dateT.month, dateT.day, days);
    system("pause");
    return 0;
}
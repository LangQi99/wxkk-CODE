#include <stdio.h>
#include <stdbool.h>
struct Time
{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} t;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isValidTime(Time *t)
{
    if (t->year <= 0 || t->month <= 0 || t->day <= 0 || t->hour < 0 || t->minute < 0 || t->second < 0)
        return false;
    if (t->year % 4 == 0 && t->year % 100 != 0 || t->year % 400 == 0)
        days[1] = 29;
    if (t->month > 12 || t->day > days[t->month - 1])
        return false;
    return true;
}
int main()
{
    scanf("%d%d%d%d%d%d", &t.year, &t.month, &t.day, &t.hour, &t.minute, &t.second);
    if (isValidTime(&t))
        printf("%d/%d/%d %02d:%02d:%02d", t.year, t.month, t.day, t.hour, t.minute, t.second);
    else
        printf("输入的时间无效！");
    return 0;
}

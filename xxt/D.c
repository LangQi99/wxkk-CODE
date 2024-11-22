#include <stdio.h>
#include <stdlib.h>
void numberToString1(long num, char *str)
{
    int isn = 0;
    if (num < 0)
    {
        isn = 1;
        num = -num;
    }
    char *start = str;
    if (isn)
    {
        *str = '-';
        str++;
    }
    if (num == 0)
    {
        *str = '0';
        str++;
        *str = '\0';
        return;
    }
    while (num != 0)
    {
        *str = num % 10 + '0';
        str++;
        num /= 10;
    }
    *str = '\0';
    char *end = str - 1;
    char temp;
    if (isn)
    {
        start++;
    }
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
char *numberToString2(long num)
{
    int isn = 0;
    if (num < 0)
    {
        isn = 1;
        num = -num;
    }
    char *str = (char *)malloc(9999);
    char *res = str;
    char *start = str;
    if (isn)
    {
        *str = '-';
        str++;
    }
    if (num == 0)
    {
        *str = '0';
        str++;
        *str = '\0';
        return res;
    }
    while (num != 0)
    {
        *str = num % 10 + '0';
        str++;
        num /= 10;
    }
    *str = '\0';
    char *end = str - 1;
    char temp;
    if (isn)
    {
        start++;
    }
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    return res;
}
int main()
{
    long num;
    scanf("%ld", &num);
    printf("%s\n", numberToString2(num));
    return 0;
}

#include <stdio.h>
#include <string.h>
int mystrlen(char *str)
{
    // return strlen(str);
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}
int main()
{
    char a[100000] = {0};
    char ch;
    int i = 0;
    while ((ch = getchar()) != EOF)
    {
        a[i] = ch;
        i++;
    }
    a[i] = '\0';
    // gets(str);
    printf("%d", mystrlen(a));
    return 0;
}
/*
正确答案：
程序语言 C/C++
#include <stdio.h>



//* 方法1：通过计数器计算字符串长度

int mystrlen(char *str)

{

    int count = 0;

    while (*str++ != '\0')

        count++;

    return count;

}



//* 方法2：通过指针运算计算字符串长度

int mystrlen2(char *str)

{

    char *end = str;

    while (*end++ != '\0')

        ;

    return end - str - 1;

}



int main()

{

    char str[21] = {0};

    scanf("%20[^\n]", str);

    printf("%d\n", mystrlen(str)); // 方法1结果

    // printf("%d\n", mystrlen2(str)); // 方法2结果



    return 0;

}


用例1：
输入
hello world

输出
11

用例2：
输入
hi 12*-3\

输出
11

用例3：
输入
111111111111111111111111

输出
20

用例4：
输入
输出
0



*/
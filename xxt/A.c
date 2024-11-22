#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *mystrcat(char *dest, const char *src)
{
    char *res = (char *)malloc(100);
    res[0] = '\0';
    char *p = res;
    while (*dest != '\0')
    {
        *p = *dest;
        p++;
        dest++;
    }
    while (*src != '\0')
    {
        *p = *src;
        p++;
        src++;
    }
    *p = '\0';
    return res;
}

int main()
{
    char s1[100] = "\0";
    char s2[100] = "\0";
    scanf("%20[^\n]", s1);
    scanf("%*[^\n]");
    scanf("%*c");
    scanf("%20[^\n]", s2);
    printf("%s\n", mystrcat(s1, s2));
    return 0;
}
/*

正确答案：
程序语言 C/C++
#include <stdio.h>

#include <string.h>



// 合并两个字符串并返回合并后的字符串指针

char *mystrcat(char *dest, const char *src)

{

    char *result = dest;  // 记录返回的字符串地址

    while (*dest != '\0') // 移动目标字符串的指针到'\0'

        dest++;



    while (*src != '\0') // 遍历源字符串，逐个字符添加到目标字符串末尾

        *dest++ = *src++;



    *dest = '\0'; // 在目标字符串末尾添加'\0'标记



    return result;

}



int main()

{

    char str1[41] = {0}; // 第一个字符串要有足够的空间保存合并后的内容

    char str2[21] = {0};

    scanf("%20[^\n]", str1); // 输入第一个字符串，字符串长度不能超过100



    // 通过以下两个语句，清空缓存

    scanf("%*[^\n]");

    scanf("%*c");



    scanf("%20[^\n]", str2); // 输入第二个字符串，字符串长度不能超过100



    char *result = mystrcat(str1, str2); // 将第二个字符串合并到第一个字符串

    printf("%s\n", result);



    return 0;

}


用例1：
输入
hello world !!!

输出
hello world!!!

用例2：
输入
hello world

输出
hello world

用例3：
输入
111111111111111111111111 222222222222222222222222

输出
1111111111111111111122222222222222222222

*/
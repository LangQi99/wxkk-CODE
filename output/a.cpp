#pragma warning(disable : 4996)
#include <stdio.h>
int main()
{
    int a[5] = {4, 2, 3, 6, 1};
    int i, j, temp;
    for (i = 1; i < 5; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
            a[j + 1] = a[j];
        a[j + 1] = temp;
    }
    for (i = 0; i < 5; i++)
        printf("%4d", a[i]);
}

// 2  4  6  1
// temp = 3;

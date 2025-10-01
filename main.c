#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    unsigned int u = UINT_MAX;
    long unsigned int l = (unsigned long)UINT_MAX + 1024;
    int res = (int)((long)INT_MAX * 2);

    _printf("%b\n", 1024);
    _printf("%b\n", -1024);
    _printf("%b\n", 0);
    _printf("%b\n", u);
    _printf("%lb\n", l);
    _printf("There is %b bytes in %b KB\n", 1024, 1);
    _printf("%b - %b = %b\n", 2048, 1024, 1024);
    _printf("%b + %b = %lb\n", INT_MAX, INT_MAX, (unsigned long)res);

    return 0;
}

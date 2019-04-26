/*
 * =====================================================================================
 *
 *       Filename:  common.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2014年07月17日 16时35分40秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (sw), andy_y_li@163.com
 *        Company:  ldpy
 *
 * =====================================================================================
 */
#include <stdio.h>
#include "common.h"

void swap(int *a, int *b)
{
    if (a == NULL || b == NULL) {
        return;
    }
    int temp = *a;
    *a = *b;
    *b = temp;
}

char *reverse0(char *str, int length)
{
    for (int i = 0; i < length / 2; ++i) {
        str[length] = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = str[length];
    }
    str[length] = 0;

    return str;
}
char *reverse1(char *str, int length)
{
    for (int i = 0; i < length / 2; ++i) {
        str[i] = str[i] + str[length - 1 - i];
        str[length - 1 - i] = str[i] - str[length - 1 - i];
        str[i] = str[i] - str[length - 1 - i];
    }
    return str;
}
char *reverse2(char *str, int length)
{
    for (int i = 0; i < length / 2; ++i) {
        str[i] = str[i] ^ str[length - 1 - i];
        str[length - 1 - i] = str[i] ^ str[length - 1 - i];
        str[i] = str[i] ^ str[length - 1 - i];
    }
    return str;

}


bool isPowerOf2(unsigned int n)
{
    return (n & (n - 1));
}


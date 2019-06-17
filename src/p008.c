/*
 * =====================================================================================
 *
 *       Filename:  p008.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/17/19 00:14:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>

int myAtoi(char* str)
{
    char *s;
    long n = 0, sign = 0;

    while (*str == ' ' || *str == '\t') {
        str++;
    }

    bool digit = false;
    for (s = str; *s != '\0'; s++) {
        if (isdigit(*s)) {
            digit = true;
            int d = *s - '0';
            if (sign) {
                if (-n < (INT_MIN + d) / 10) {
                    n = INT_MIN;
                    break;
                }
            } else {
                if (n > (INT_MAX - d) / 10) {
                    n = INT_MAX;
                    break;
                }
            }
            n = n * 10 + d;
        } else if (digit == false && *s == '-' && isdigit(*(s + 1))) {
            sign = 1;
        } else if (digit == false && *s == '+' && isdigit(*(s + 1))) {
            sign = 0;
        } else {
            break;
        }
    }

    return sign ? -n : n;
}

int main()
{
    int n = myAtoi("0-1");
    printf("n = %d\n", n);
    return 0;
}


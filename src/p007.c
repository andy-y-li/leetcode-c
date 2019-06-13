/*
 * =====================================================================================
 *
 *       Filename:  p007.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/19 21:45:36
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

int reverse(int x){
    int flag = 1;
    long y = x;
    if (x < 0) {
        if (y < INT_MIN) {
            return 0;
        }
        flag = -1;
        y = y * (-1);
    }

    long p = 0;
    for (;y > 0;) {
        int t = y % 10;
        p = p * 10 + t;
        if (p > INT_MAX) { // overflow
            p = 0;
            break;
        }
        y = y / 10;
    }
    p = p * flag;
    return p;
}

int main()
{
    int p = reverse(320);
    printf("p=%d\n", p);
    return 0;
}


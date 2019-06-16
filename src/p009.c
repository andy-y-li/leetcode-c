/*
 * =====================================================================================
 *
 *       Filename:  p009.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/23/18 10:36:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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


bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int y = reverse(x);
    return (x==y);
}

int main()
{
    int x = 121;
    bool y = isPalindrome(x);

    printf("%d is %s a palindrome\n",x, y?"":"Not");
    return 0;
}


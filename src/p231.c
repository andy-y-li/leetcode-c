/*
 * =====================================================================================
 *
 *       Filename:  p231.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/18/19 15:58:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n){
    if (n < 0) {
        return false;   
    }
    return (n && !(n & (n - 1)));
}

int main()
{
    int n = 16;
    bool ret = isPowerOfTwo(n);
    printf("%d is %s powerOf2\n", n, (ret?"":"NOT"));
    return 0;
}

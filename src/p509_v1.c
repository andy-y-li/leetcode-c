/*
 * =====================================================================================
 *
 *       Filename:  p509_v1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/16/19 17:21:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int fib(int N)
{
    int curr = 0, next = 1;
    while (N-- > 0) {
        next = next + curr;
        curr = next - curr;
    }
    return curr;
}


int main() {
    int v = fib(10);
    printf("v = %d\n", v);
    return 0;
}

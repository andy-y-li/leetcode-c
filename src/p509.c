/*
 * =====================================================================================
 *
 *       Filename:  p509.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/16/19 17:06:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

int fib(int N){
    if (N < 2) {
        return N;
    }
    return fib(N - 1) + fib(N - 2);
}

int main() {
    int v = fib(10);
    printf("v = %d\n", v);
    return 0;
}

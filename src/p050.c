/*
 * =====================================================================================
 *
 *       Filename:  p50.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/19 16:15:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

double ePow(double x, int n)
{
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return x;
    }
    double temp = ePow(x, n/2);
    temp *= temp;
    if (n%2 != 0) {
        temp *= x;
    }
    return temp;
}

double myPow(double x, int n){
    int a = abs(n);
    double result = ePow(x, a);

    if (n < 0) {
        result = 1/ result;
    }
    return result;
}

int main()
{
    double f = myPow(3.1,4);
    printf("result:%f\n", f);
    return 0;
}

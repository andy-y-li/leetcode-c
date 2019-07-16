/*
 * =====================================================================================
 *
 *       Filename:  p070.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/16/19 16:19:04
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
#include <string.h>

int climb_stairs(int i, int n, int *memo) 
{
    if (i > n) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i] > 0) {
        return memo[i];
    }
    memo[i] = climb_stairs(i + 1, n, memo) + climb_stairs(i + 2, n, memo);
    return memo[i];
}

int climbStairs(int n){
    int *memo = (int *)malloc(sizeof(int) * (n + 1));
    memset(memo,0,sizeof(int) * (n + 1));
    int v = climb_stairs(0, n, memo);
    free(memo);
    return v;
}

int main() {
    int n = 10;
    int v = climbStairs(n);
    printf("v = %d\n", v);
    return 0;    
}

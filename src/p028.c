/*
 * =====================================================================================
 *
 *       Filename:  p028.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/17/19 17:15:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    int m = strlen(haystack);
    int n = strlen(needle);
    if (n == 0) {
        return 0;
    }
    if (m < n) {
        return -1;
    }
    for (int i = 0; i <= m - n; i++){
        int j = 0;
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return -1;
}

int main()
{
    char s[] = "hello kitty!";
    char s1[] = "lo";
    int i = strStr(s, s1);
    printf("location:%d\n", i);
    return 0;
}

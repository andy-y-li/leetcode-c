/*
 * =====================================================================================
 *
 *       Filename:  p028_v1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/18/19 11:42:44
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

char *get_next(char *str)
{
    int len = strlen(str);
    char *next = (char *)malloc(sizeof(char) * len);
    next[0] = -1;

    int j = 0;
    int k = -1;

    while (j < len -1) {
        if (k == -1 || str[j] == str[k]) {
            k++;
            j++;
            if (str[j] != str[k]){
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
    return next;
}

int strStr(char * haystack, char * needle)
{
    int m = strlen(haystack);
    int n = strlen(needle);

    if (n == 0) {
        return 0;
    }
    char *next = get_next(needle);

    int i = 0, j = 0;

    while(i < m && j < n) {
        if (j == -1 || haystack[i] == needle[j]) {
            i++;
            j++;
        } else {
                j = next[j];
        }
    }
    free(next);
    if (j == n) {
        return i - n;
    }
    return -1;
}

int main()
{
    char s[] = "BBC ABCDAB ABCDABCDABDE";
    char s1[] =  "ABCDABD";

    int i = strStr(s, s1);
    printf("location:%d\n", i);
    return 0;
}

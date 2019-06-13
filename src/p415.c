/*
 * =====================================================================================
 *
 *       Filename:  p415.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/19 14:45:09
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

int reverse(char *str)
{
    if (NULL == str) {
        return -1;
    }
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char t = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = t;
    }
    return 0;
}

char *addStrings(char * a, char * b){
    reverse(a);
    reverse(b);
    int len1 = strlen(a);
    int len2 = strlen(b);
    int plus = 0;
    int len = len1<len2?len2+2:len1+2;
    char *c = (char *) malloc(sizeof(char) * len);
    c[len - 1] = '\0';
    int i;
    for (i = 0; i < len1 || i < len2; i++) {
        int v1 = 0, v2 = 0; 
        if (i < len1) {
            v1 = a[i] -'0';
        }
        if (i < len2) {
            v2 = b[i] -'0';
        }
        int sum = v1 + v2 + plus;
        c[i] = sum % 10 + '0';
        plus = sum>=10?1:0;

    }
    if (plus) {
        c[i] = '1';
    }else {
        c[i] = '\0';
    }
    reverse(c);
    return c;
}

int main()
{
    char s1[32];
    strcpy(s1, "123456");
    char s2[32];
    strcpy(s2, "345620");
    char *s = addStrings(s1,s2);
    printf("s:%s\n", s);
    free(s);
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  p443_v1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/16/19 17:56:45
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

void itoa(char n, char *s)
{
    int sign;
    if ((sign = n) < 0) {
        n = -n;
    }
    int i = 0;
    do {
        s[i++] = n %10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);
}

int compress(char* chars, int charsSize){
    int i = 0;
    int t = 0;

    while (i < charsSize && t < charsSize) {
        chars[t++] = chars[i];
        int temp = i;
        while (i < charsSize && chars[i] == chars[t-1]) {
            i++;
        }
        if (i - temp > 1) {
            char buf[5];
            itoa(i - temp, buf);
            for (int i = 0; i < (int)strlen(buf); i++){
                chars[t++] = buf[i];
            }
        }
    }
    if (t < charsSize) {
        chars[t] = '\0';
    }
    return t;
}

int main()
{
    char *str = (char *)malloc(128);
    strcpy(str, "aabb");

    printf("input str:%s\n", str);
    int n = compress(str, strlen(str));
    printf("output len:%d, str:%s\n", n, str);
    free(str);
    return 0;
}

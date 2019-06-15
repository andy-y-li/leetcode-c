/*
 * =====================================================================================
 *
 *       Filename:  p038_v2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/15/19 10:37:52
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

char *countAndSay(int n){
    char *s = (char *)malloc(sizeof(char) + 1);
    s[0] = '1';
    s[1] = '\0';

    for (int i = 0; i < n -1; i++) {
        char *str = (char *)malloc(sizeof(char)); 
        int cnt = 0;
        int len = strlen(s);
        for (int j = 0, k = 0; j < len;) {
            if (s[j] == s[j + k]) {
                k++;
            } else {
                char *temp = (char *)realloc(str, (cnt + 1) * 2 + 1);
                if (!temp) {
                    break;
                }
                str = temp;
                str[cnt * 2] = k + '0';
                str[cnt * 2 + 1] = s[j];
                j += k;
                k = 1;
                cnt++;
            }
        }
        str[cnt * 2] = '\0';
        free(s);
        s = str;
    }
    return s;
}

int main()
{
        /*
        char *s = countAndSay(2);
        printf("s%d:%s\n",2, s);
        free(s);*/
    for (int i = 1; i <= 30; i++) {
        char *s = countAndSay(i);
        printf("s%d:%s\n",i, s);
        free(s);
    }
    return 0;
}


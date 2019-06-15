/*
 * =====================================================================================
 *
 *       Filename:  p038.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/14/19 09:59:08
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

int findFromStr(char *s, int len, char c)
{
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == c) {
            cnt++;
            continue;
        } else {
            break;
        }
    }
    return cnt;
}

char *getSay(char *s)
{
    int len = strlen(s);
    char *str = (char *)malloc(sizeof(char) * 3);
    int loop_count = 0;
    for (int i = 0; i < len;) {
        int cnt = findFromStr(s+i,len-i,s[i]);
        if (i == 0) { // First
            str[0] = cnt + '0';
            str[1] = s[i];
        } else {
            char *temp = (char *) realloc(str, loop_count * 2 + 3);
            if (!temp) {
                break;
            }
            str = temp;
            str[loop_count * 2] = cnt + '0';
            str[loop_count * 2 + 1] = s[i];
        }
        loop_count++;
        i += cnt;
    }

    str[loop_count * 2] = '\0';
    return str;
}

char *countAndSay(int n){
    if (n == 1) {
        char *s = (char *)malloc(sizeof(char) + 1);
        s[0] = '1';
        s[1] = '\0';
        return s;
    }
    char *s1 = countAndSay(n-1);
    return getSay(s1);
}

int main()
{
/*    
    for (int i = 1; i <= 30; i++) {
        char *s = countAndSay(i);
        printf("s%d:%s\n",i, s);
        free(s);
    }
*/
    char *s = countAndSay(20);
    printf("s20:%s\n", s);
    free(s);
    return 0;
}

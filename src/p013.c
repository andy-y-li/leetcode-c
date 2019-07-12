/*
 * =====================================================================================
 *
 *       Filename:  p013.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/19 13:08:54
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
#include <stdlib.h>
#include <stdbool.h>

char *substr(char *s, int pos, int len)
{
    int l = strlen(s);
    if (pos + len > l) {
        return NULL;
    }
    char *s1 = (char *)malloc(sizeof(char) * len + 1);
    memset(s1,0,len + 1);
    strncpy(s1, s+pos,len);   
    s1[len] = '\0';
    return s1;
}

int getValueForKey(char *key) {
    int value[] = {1000, 800, 500, 300, 100, 80, 50, 30, 10, 8, 5, 3, 1};
    const char *dic[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int index = 0;
    bool find = false;
    int l = strlen(key);
    for (index = 0; index < 13; index++) {
        if (l != (int)strlen(dic[index])) {
            continue;
        }
        int i = 0;
        for (i = 0; i < l; i++) {
            if (key[i] != dic[index][i]) {
                break;
            }
        }
        if (i  == l) {
            find = true;
            break;
        }
    }
    if (find) {
        free(key);
        return value[index];
    }

    free(key);
    return 0;
}

int romanToInt(char * s){
    int len = strlen(s);
    int sum = getValueForKey(substr(s, 0, 1));
    for (int i = 1; i < len; i++) {
        int one = getValueForKey(substr(s, i, 1));
        int two = getValueForKey(substr(s, i - 1, 2));
        sum += two?two:one;
    }
    return sum;
}

int main()
{
    char s[] = "MCMXCIV";
    int v = romanToInt(s);
    printf("v=%d\n",v);
    return 0;
}


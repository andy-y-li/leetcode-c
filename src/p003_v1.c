/*
 * =====================================================================================
 *
 *       Filename:  p003_v1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/19 11:18:39
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
#include <stdbool.h>

int lengthOfLongestSubstring(char *s) {
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }
    bool used[256] = {false};
    int lastend = 0;
    int i, j;
    used[s[0]] = true;

    for (i = 1; i < len; i++) {
        if (used[s[i]] == false) {
            lastend = i;
            used[s[i]] = true;
        } else {
            break;
        }
    }
    int result = lastend + 1;
    if (i == len) {
        return result;
    }
    for (i = 1; i < len; i++) {
        used[s[i-1]] = false;
        if (lastend < i) {
            lastend = i;
            used[s[i]] = true;
        }
        for (j = lastend + 1; j < len; j++) {
            if (used[s[j]] == false) {
                lastend = j;
                used[s[j]] = true;
            } else {
                break;
            }
        }
        if (lastend - i + 1 > result) {
            result = lastend - i + 1;
        }
        if (result >= len - i - 1) {
            return result;
        }
    }
    return result;

}

int main()
{
    char *s = "adkdfgt";
    int l = lengthOfLongestSubstring(s);
    printf("max len:%d\n",l);
    return 0;
}


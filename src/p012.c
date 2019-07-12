/*
 * =====================================================================================
 *
 *       Filename:  p012.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/04/19 15:15:37
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

char *intToRoman(int num){
    char *str = (char *)malloc(sizeof(char) * 20);
    memset(str,0,20);
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *dic[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;


    while (num > 0 && i < 13) {
        if (num >= value[i]) {
           str = strcat(str,dic[i]);
           num -= value[i];
        } else {
            i++;
        }
    }

    return str;
}

int main()
{
    int num = 3256;
    char *s = intToRoman(num);
    printf("int:%d Roman:%s\n", num, s);
    free(s);
    return 0;
}

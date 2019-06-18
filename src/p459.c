/*
 * =====================================================================================
 *
 *       Filename:  p459.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/18/19 10:36:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool repeatedSubstringPattern(char * s){
int len = strlen(s);
    char str[2 * len - 1];
    memset(str, 0, sizeof(str));
    strncat(str, s + 1, len - 1);
    strncat(str, s, len - 1);
    
    return strstr(str, s);
}

int main()
{
    //char s[] = "ababc";
    char s[] = "abab";
    bool ret = repeatedSubstringPattern(s);
    printf("%s is %s repeatedSubstringPattern\n", s, (ret?"":"NOT"));
    return 0;
}

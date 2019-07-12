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
#include "uthash.h"

struct RomanDict{
    char key[10];             /* key */
    int value;
    UT_hash_handle hh;         /* makes this structure hashable */
};

struct RomanDict *s, *tmp, *users = NULL;

void initDict()
{
    int value[] = {1000, 800, 500, 300, 100, 80, 50, 30, 10, 8, 5, 3, 1};
    const char *key[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (int i = 0; i < 13; i++) {
        s = (struct RomanDict *)malloc(sizeof(struct RomanDict));
        if (s == NULL) {
            exit(-1);
        }
        strcpy(s->key,key[i]);
        s->value = value[i];
        HASH_ADD_STR( users, key, s);
    } 
}

void releaseDict()
{
    HASH_ITER(hh, users, s, tmp) {
        HASH_DEL(users, s);
        free(s);
    }
}

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
    HASH_FIND_STR( users, key, s);
    free(key);
    if (s != NULL) {
        return s->value;
    }
    return 0;
}

int romanToInt(char * s){
    initDict();
    int len = strlen(s);
    int sum = getValueForKey(substr(s, 0, 1));
    for (int i = 1; i < len; i++) {
        int one = getValueForKey(substr(s, i, 1));
        int two = getValueForKey(substr(s, i - 1, 2));
        sum += two?two:one;
    }
    releaseDict();
    return sum;
}

int main()
{
    char s[] = "MCMXCIV";
    int v = romanToInt(s);
    printf("v=%d\n",v);
    return 0;
}


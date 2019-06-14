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

typedef struct section {
    char val;
    int count;
    struct section *next;
} Section;

char *getStringFromList(Section *L)
{
    char *s = NULL;
    int cnt = 0;
    for (;L;) {
        if (!s) { // First
            s = (char *)malloc(sizeof(char) * 3);
            s[cnt++] = L->count + '0';
            s[cnt++] = L->val;
            L = L->next;
            continue;
        } 
        char *temp = (char *)realloc(s, sizeof(char) * cnt + 3);
        if (!temp) {
        // Error and break
            break;
        }
        s = temp;
        s[cnt++] = L->count + '0';
        s[cnt++] = L->val;

        L = L->next;
    }
    s[cnt] = '\0';
    return s;
}

void release(Section *L)
{
    do {
        Section *p = L->next;
        free(L);
        L = p;
    } while (L);
}

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
    Section *L = (Section *)malloc(sizeof(Section));
    Section *header = L;
    L->next = NULL;

    int len = strlen(s);

    for (int i = 0; i < len;) {
        int cnt = findFromStr(s+i,len-i,s[i]);
        if (i == 0) { // First node
            L->val = s[i];
            L->count = cnt;
            L->next = NULL;
        } else {
            Section *p = (Section *)malloc(sizeof(Section));
            p->val = s[i];
            p->count = cnt;
            p->next = NULL;
            L->next = p;
            L = p;
        }
        i += cnt;
    }

    char *strResult = getStringFromList(header);

    release(L);
    return strResult;
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
    }*/
        char *s = countAndSay(20);
        printf("s20:%s\n", s);
        free(s);
    return 0;
}

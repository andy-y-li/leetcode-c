/*
 * =====================================================================================
 *
 *       Filename:  p067.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/12/19 23:47:00
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
#include <stdbool.h>
#include "list.h"

ListNode *addToList(char *str)
{
    int len = strlen(str);
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    bool firstNode = true;
    for (int i = len; i > 0; i-- ) {
        int v = str[i - 1] - '0';
        if (firstNode) {
            p->val = v;
            p->next = NULL;
            firstNode = false;
            continue;
        } else {
            addNode(p, v);
        }
    }
    return p;
}

ListNode *addTowList(ListNode *L1, ListNode *L2)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    
    bool firstNode = true;
    int plus = 0;
    for (; L1 || L2;) {
        if (firstNode) {
            int v1 = L1->val;
            int v2 = L2->val;
            int sum = v1 + v2;
            plus = (sum > 1?1:0);

            p->val = sum % 2;
            p->next = NULL;
            L1 = L1->next;
            L2 = L2->next;
            firstNode = false;
            continue;
        } else {
            if (L1 == NULL && L2 == NULL) {
                break;
            }
            int v1 = L1?L1->val:0;
            int v2 = L2?L2->val:0;
            int sum = v1 + v2 + plus;
            plus = (sum > 1?1:0);

            addNode(p, sum % 2);
            L1 = L1?L1->next:NULL;
            L2 = L2?L2->next:NULL;
        }

    }
    if (plus) {
        addNode(p, plus);
    }
   return p;
}

char *getStringValue(ListNode *L)
{
    int len = length(L);
    char * str = (char *)malloc(sizeof(char) * (len + 1));
    str[len] = '\0';
    for (int i = len; i > 0; i--) {
        str[i - 1] = L->val + '0';
        L = L->next;
    }
    return str;
}

char * addBinary(char * a, char * b){
    ListNode *L1 = addToList(a);
    ListNode *L2 = addToList(b);
    
    ListNode *p = addTowList(L1, L2);
    
    char *str = getStringValue(p);
    release(L1);
    release(L2);
    release(p);
    return str;
}

int main()
{
    char *s = addBinary("10001", "1101001");
    printf("s:%s\n", s);
    free(s);
    return 0;
}

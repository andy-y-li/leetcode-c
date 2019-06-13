/*
 * =====================================================================================
 *
 *       Filename:  list.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/13/19 10:35:11
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
#include <math.h>
#include "list.h"

int addNode(ListNode *L, int v)
{
    if (L == NULL) {
        return -1;
    }
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->val = v;
    p->next = NULL;

    for (;L->next != NULL;) {
        L = L->next;
    }
    L->next = p;
    return 0;
}

int length(ListNode *L)
{
    int len = 1;
    for (;L->next != NULL;) {
        len++;
        L = L->next;
    }
    return len;
}

// 2->4->3: 342
int getValue(ListNode *L)
{
    int sum = 0;
    int n = 0;
    for (sum = 0;L->next != NULL;) {
        sum += L->val * pow(10,n);
        L = L->next;
        n++;
    }
    sum += L->val * pow(10,n);

    return sum;
}

void release(ListNode *L)
{
    do {
        ListNode *p = L->next;
        free(L);
        L = p;
    } while (L);
}

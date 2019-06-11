/*
 * =====================================================================================
 *
 *       Filename:  p002.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/11/19 14:46:42
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

/**
 * Definition for singly-linked list.
 */
typedef struct Node {
    int val;
    struct Node *next;
} ListNode ;

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

int length(ListNode *L)
{
    int len = 1;
    for (;L->next != NULL;) {
        len++;
        L = L->next;
    }
    return len;
}

ListNode* addTwoNumbers(ListNode* L1, ListNode* L2){
    int v1 = getValue(L1);
    int v2 = getValue(L2);

    int sum = v1 + v2;

    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->val = sum % 10;
    p->next = NULL;
    sum = sum / 10;

    if (sum) {
        for (;sum / 10;) {
            addNode(p, sum % 10);
            sum = sum / 10;
        }
        addNode(p, sum % 10);
    }

    return p;
}

int main()
{
    ListNode *L1 = (ListNode *)malloc(sizeof(ListNode));
    ListNode *L2 = (ListNode *)malloc(sizeof(ListNode));

    L1->val = 2;
    L1->next = NULL;
    addNode(L1, 4);
    addNode(L1, 3);

    L2->val = 5;
    L2->next = NULL;
    addNode(L2, 6);
    addNode(L2, 4);

    ListNode *p = addTwoNumbers(L1, L2);

    int v1 = getValue(L1);
    int v2 = getValue(L2);

    int sum = getValue(p);
    printf("v1 = %d, v2 = %d, sum = %d\n", v1, v2, sum);
    return 0;
}

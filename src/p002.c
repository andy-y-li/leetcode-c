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
#include <stdbool.h>
#include "list.h"

ListNode* addTwoNumbers(ListNode* L1, ListNode* L2){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    
    bool firstNode = true;
    int plus = 0;
    for (; L1 || L2;) {
        if (firstNode) {
            int v1 = L1->val;
            int v2 = L2->val;
            int sum = v1 + v2;
            plus = (sum > 9?1:0);

            p->val = sum % 10;
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
            plus = (sum > 9?1:0);

            addNode(p, sum % 10);
            L1 = L1?L1->next:NULL;
            L2 = L2?L2->next:NULL;
        }

    }
    if (plus) {
        addNode(p, plus);
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

    release(L1);
    release(L2);
    release(p);
    return 0;
}

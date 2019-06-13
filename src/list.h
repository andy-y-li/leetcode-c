/*
 * =====================================================================================
 *
 *       Filename:  list.h
 *
 *    Description: singly-linked list. 
 *
 *        Version:  1.0
 *        Created:  06/13/19 10:30:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef _LIST_H
#define _LIST_H

/**
 * Definition for singly-linked list.
 */
typedef struct Node {
    int val;
    struct Node *next;
} ListNode ;

int addNode(ListNode *L, int v);
int length(ListNode *L);
int getValue(ListNode *L);
void release(ListNode *L);

#endif


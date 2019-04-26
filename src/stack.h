#ifndef _STACK_H
#define _STACK_H

#include "common.h"

#define MAX_STSIZE 128
typedef char Item;

typedef struct{
	Item data[MAX_STSIZE];
	int top;
}Stack;

void createStack(Stack *st);
BOOL push(const Item data,Stack *st);
BOOL pop(Item *data,Stack *st);
BOOL stIsEmpty(const Stack *st);
BOOL stIsFull(const Stack *st);
BOOL destroyStack(Stack *st);

#endif // #ifndef _STACK_H


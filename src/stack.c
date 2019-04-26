#include <stdio.h>
#include "stack.h"


void createStack(Stack *st)
{
	st->top = -1;
}

BOOL push(const Item data,Stack *st)
{
	if (stIsFull(st)){
		return FALSE;
	}
	st->data[++st->top] = data;
	return TRUE;
}

BOOL pop(Item *pdata,Stack *st)
{
	if (stIsEmpty(st)){
		return FALSE;
	}
	*pdata = st->data[st->top--];
	return TRUE;
}

BOOL stIsEmpty(const Stack *st)
{
	return st->top == -1;
}

BOOL stIsFull(const Stack *st)
{
	return st->top == MAX_STSIZE - 1;
}

BOOL destroyStack(Stack *st)
{
	return TRUE;
}


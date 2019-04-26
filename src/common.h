#ifndef _ARI_COMMON_H
#define _ARI_COMMON_H

#include <stdbool.h>

#define TRUE 1
#define FALSE 0
#define BOOL   int

#define Status int
#ifndef OK
#define OK     1
#endif
#ifndef ERROR
#define ERROR  0
#endif

#define SWAP(a,b,t)  ((t) = (a),(a) = (b),(b) = (t))

#define LESS -1
#define EQUAL 0
#define MORE  1

#define COMPARE(a,b) ((a) < (b)?LESS:((a) == (b)?EQUAL:MORE))
#define STRCMP(a,R,b)   (strcmp(a,b) R 0)
#define CMP(a,R,b)      ((a) (R) (b))

#define LESS_THAN(a, b)      ((a) < (b))
#define GREATER_THAN(a, b)   ((a) > (b))
void swap(int *a, int *b);

char *reverse0(char *str, int length);
char *reverse1(char *str, int length);
char *reverse2(char *str, int length);

bool isPowerOf2(unsigned int n);

#endif // #ifndef _ARI_COMMON_H


/*
 * =====================================================================================
 *
 *       Filename:  findLength.c
 *
 *    Description: Given two integer arrays A and B, 
 *                 return the maximum length of an subarray that appears in both arrays. 
 *
 *        Version:  1.0
 *        Created:  04/18/18 20:35:42
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  gk
 *
 * =====================================================================================
 */

#include <stdio.h>

void show(int *A, int s, int e) {
    printf("start:%d,end:%d\n", s, e);
    for (int i = s; i < e + 1; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int locationInArray(int aValue, int *B, int BSize) {
    for (int j = 0; j < BSize; j++) {
        if (aValue == B[j]) {
            return j;
        }
    }
    return -1;
}

int isSubArray(int *A, int s, int e, int *B, int BSize) {
    printf("checking start:%d,end:%d\n", s, e);
    int pre_location = -1;
    for (int i = s; i < e+1;i++) {
        int location = locationInArray(A[i], B, BSize);
        if (location != -1) {
            if (pre_location == -1) {
                pre_location = location;
                continue;
            }
            else {
                if (pre_location + 1 == location) {
                    pre_location++;
                    continue;
                } else {
                    if (B[pre_location + 1] == A[i]) {
                        pre_location++;
                        continue;
                    } else {
                        return 0;
                    }       
                }

            }
        } else {
            return 0;
        }
    
    }
    return 1;

}

int findLength(int* A, int ASize, int* B, int BSize) {
    int len = 0;
    int maxLen = 0;

    for (int start = 0; start < ASize; start++) {
        for (int end = start; end < ASize; end++) {
            if (isSubArray(A, start, end, B, BSize)) {
                show(A, start, end);
                len = end - start + 1;
                maxLen = (maxLen < len?len:maxLen);
            }    
        }
    }
    return maxLen;
}

int main() {
    //int a[] = {1,2,3,2,1};
    //int b[] = {3,2,1,4,7};
    int a[] = {0,0,0,0,0,0,1,0,0,0};
    int b[] = {0,0,0,0,0,0,0,1,0,0};
    int len = findLength(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
    printf("len: %d\n", len);
    return 0;
}

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

int locationInArray(int aValue, int *B, int BSize) {
    for (int j = 0; j < BSize; j++) {
        if (aValue == B[j]) {
            return j;
        }
    }
    return -1;
}

int isSubArray(int *A, int s, int e, int *B, int BSize) {
    int pre_location = -1;
    for (int i = s; i < e-s+1;i++) {
        int location = locationInArray(A[i], B, BSize);
        if (location != -1) {
            if (pre_location == -1) {
                pre_location = location;
            }
            else {
                if (pre_location + 1 == location) {
                    continue;
                } else {
                    if (B[pre_location + 1] == A[i]) {
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

    for (int start = 0; start < ASize -1; start++) {
        for (int end = start; end < ASize - start; end++) {
            if (isSubArray(A, start, end, B, BSize)) {
                len = end - start + 1;
                maxLen = (maxLen < len?len:maxLen);
            }    
        }
    }
    return maxLen;
}

int main() {
    int a[] = {1,3,2,1,2};
    int b[] = {3,2,1,4,7};
    int len = findLength(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int));
    printf("len: %d\n", len);
    return 0;
}

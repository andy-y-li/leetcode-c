/*
 * =====================================================================================
 *
 *       Filename:  selectionSort.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/23/18 16:41:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define CMP(a,b) ((a)>=(b)?1:0)

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void SelectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(A, min, i);
        }
    }
}

int singleNumber(int* nums, int numsSize) {
    int i = 0;
    for (i = 0; i < numsSize -1; i++) {
        if (CMP(nums[i], nums[i+1])) {
            continue;
        }
        if (i == 0) {
            return nums[i];
        }
        if (CMP(nums[i-1],nums[i])) {
            continue;
        }
        return nums[i];
    }
    if (i == numsSize - 1) {
        return nums[i];
    }
   return -1;
}

int main()
{
    int b[] = {2,5,3,5,4,3,4};
    int len = sizeof(b) / sizeof(int);
    SelectionSort(b, len);

    int v = singleNumber(b, len);
    printf("V = %d\n", v);
    return 0;
}

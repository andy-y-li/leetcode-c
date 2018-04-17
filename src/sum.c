/*
 * =====================================================================================
 *
 *       Filename:  sum.c
 *
 *    Description:  给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
 *
 *        Version:  1.0
 *        Created:  04/17/18 16:55:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  gk
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *buf = (int *)malloc(sizeof(int) * 2);
   
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = i + 1; j < numsSize;j++ ) {
            if (nums[i] + nums[j] == target) {
                buf[0] = i;
                buf[1] = j;
                return buf;
            }
        } 
    }
    free(buf);
    return NULL;
}

int main() {
    int nums[] = {2,7,11,15};
    int *buf = twoSum(nums, sizeof(nums)/sizeof(int), 9);

    if (buf == NULL) {
        printf("Can not found the two number.\n");
        return 0;
    }

    printf("[%d, %d]\n", buf[0], buf[1]);
    free(buf);

    return 0;

}

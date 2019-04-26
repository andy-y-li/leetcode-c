/*
 * =====================================================================================
 *
 *       Filename:  findElement.c
 *
 *    Description:  给出一个有序数组 A，数组中的每个数字都是 独一无二的，
 *    找出从数组最左边开始的第 K 个缺失数字。
 *
 *        Version:  1.0
 *        Created:  04/26/19 15:51:01
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>

typedef struct {
    int index;
    int value;
}Node;

int missingElement(int* nums, int numsSize, int k) {
    Node u;
    u.index = 0;
    u.value = 0;
    int i = 0;
    for (i = 0; i < numsSize - 1;i++) {
        int deta = nums[i + 1] - nums[i];
        if (deta == 1) {
            continue;
        }
        u.value = nums[i] + 1;
        u.index++;
        printf("u[%d]=%d\n", u.index,u.value);
        if (u.index == k) {
            return u.value;
        }
        for (;u.value < nums[i + 1];) {
            if (u.value + 1 != nums[i + 1]) {
                u.value++;
                u.index++;
                printf("u[%d]=%d\n", u.index,u.value);
                if (u.index == k) {
                    return u.value;
                }
            } else {
                break;
            }
        }
    }
    if (u.value < nums[i]) {
        return nums[i] + (k - u.index);
    } else {
        return u.value + (k - u.index);
    }

    return -1;
}

int main()
{
    //int a[] = {4,7,9,10};
    int a[] = {1,2,4};
    int v = missingElement(a,3,3);
    printf("v=%d\n",v);
    return 0;
}

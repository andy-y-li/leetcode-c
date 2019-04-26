/*
 * =====================================================================================
 *
 *       Filename:  removeDuplicate.c
 *
 *    Description:  给定一个排序数组，你需要在原地删除重复出现的元素，
 *                  使得每个元素只出现一次，返回移除后数组的新长度
 *
 *        Version:  1.0
 *        Created:  04/17/18 16:36:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  gk
 *
 * =====================================================================================
 */

#include <stdio.h>

void show(int *num, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

int removeDuplicate(int *num, int numsSize) {
    for (int index = 0; index < numsSize - 1; index++) {
        for (int j = index + 1; j < numsSize; j++) {
            if (num[index] == num[j]){
                index = j;
            }
        }
    }   
}

int main() {
    int a[] = {0,0,1,1,2,3,3,4,4,5};
    int len = removeDuplicate(a, sizeof(a)/ sizeof(int));
    show(a, len);
    return 0;
}

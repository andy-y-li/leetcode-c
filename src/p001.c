/*
 * =====================================================================================
 *
 *       Filename:  p001.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/24/19 17:04:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "uthash.h"

typedef struct hash_node {
    int id;
    int index;
    UT_hash_handle hh;
} hash_node;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *two_nums = (int *)malloc(sizeof(int) * 2);

    hash_node *hash_table = NULL, *hash_item1 = NULL, *hash_item2 = NULL;

    for (int i = 0; i < numsSize; i++) {
        int other_id = target - nums[i];
        HASH_FIND_INT(hash_table, &other_id, hash_item1);
        if (hash_item1) { // Find it, and return.
            two_nums[0] = hash_item1->index;
            two_nums[1] = i;
            *returnSize = 2;
            return two_nums;
        }
        hash_item2 = (hash_node *)malloc(sizeof(hash_node));
        hash_item2->id = nums[i];
        hash_item2->index = i;
        HASH_ADD_INT(hash_table,id, hash_item2);
    }
    return two_nums;
}

int main()
{
    int nums[] = {2,7,11,15};
    int returnSize = 0;
    int *buf = twoSum(nums, sizeof(nums)/sizeof(int), 9, &returnSize);

    if (buf == NULL) {
        printf("Can not found the two number.\n");
        return 0;
    }

    printf("[%d, %d]\n", buf[0], buf[1]);
    free(buf);
    return 0;
}

/*
 * =====================================================================================
 *
 *       Filename:  p46.c
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  04/26/19 22:10:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void dfs(int *nums, int size, int start, int *count, int **results)
{
    int i;
    if (start == size) {
        results[*count] =(int *) malloc(size * sizeof(int));
        memcpy(results[*count], nums, size * sizeof(int));
        (*count)++;
    } else {
        for (i = start; i < size; i++) {
            swap(nums + start, nums + i);
            dfs(nums, size, start + 1, count, results);
            swap(nums + start, nums + i);
        }
    }
}

/**
 ** Return an array of arrays of size *returnSize.
 ** Note: The returned array must be malloced, assume caller calls free().
 **/
int **permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int cap = 5000;
    int **results = (int **)malloc(cap * sizeof(int *));
    *returnSize = 0;
    dfs(nums, numsSize, 0, returnSize, results);
    return results;
}


int main(int argc, char *argv[])
{
     if (argc <= 1) {
        fprintf(stderr, "Usage: %s arrayList...\n", argv[0]);
        exit(-1);
    }

    int i, j, numsSize = argc - 1;
    int *nums = (int *)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    int returnSize = 0;
    int **lists = permute(nums, numsSize, &returnSize, NULL);
    for (i = 0; i < returnSize; i++) {
        for (j = 0; j < numsSize; j++) {
            printf("%d ", lists[i][j]);
        }
        printf("\n");
    }

    return 0;
}

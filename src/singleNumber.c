/*
 * =====================================================================================
 *
 *       Filename:  singleNumber.c
 *
 *    Description:  
 *          136. Single Number:
 *          Given a non-empty array of integers, every element appears twice except for one. 
 *          Find that single one.
 *      Example 1:
 *
 *             Input: [2,2,1]
 *             Output: 1
 *
 *        Version:  1.0
 *        Created:  11/20/18 16:38:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */

int isInArray(int v, int *nums, int size) {
   //printf("find %d ,size: %d\n", v, size);
   for (int idx = 0; idx < size; idx++) {
        if (v == nums[idx]) {
            return 1;
        }
   }
   return 0;
}

int singleNumber(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
       if (isInArray(nums[i], nums + (i + 1), numsSize - (i + 1))) {
           continue;
       }
       else if (isInArray(nums[i], nums, i)) {
           continue;
       }
       return nums[i];
    }
   return -1; 
}

int main()
{
    int nums[] = {4,1,2,1,2,4,3,5,5};

    int n = singleNumber(nums, sizeof(nums)/sizeof(int));

    printf("n = %d\n", n);
    return 0;
}

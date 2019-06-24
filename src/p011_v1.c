/*
 * =====================================================================================
 *
 *       Filename:  p011.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/24/19 13:36:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>

int caclArea(int i, int h1, int j, int h2){
    int s = (j - i) * (h1 < h2?h1:h2);
    return s;
}

int maxArea(int* height, int heightSize){
    int max = 0;
    int left = 0;
    int right = heightSize - 1;
    do {
        int s = caclArea(left, height[left], right, height[right]);
        max = (max < s?s:max);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    } while (left < right);

    return max;
}

int main()
{
    int height[] = {1,8,6,2,5,4,8,3,7};
    int s = maxArea(height, sizeof(height)/ sizeof(int));
    printf("maxArea:%d\n", s);
    return 0;
}



/*
 * =====================================================================================
 *
 *       Filename:  sort.c
 *
 *    Description:  ¼òµ¥µÄÅÅĞòËã·¨¡£
 *
 *        Version:  1.0
 *        Created:  04/17/18 21:49:16
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (https://github.com/andy-y-li), andy_y_li@163.com
 *        Company:  gk
 *
 * =====================================================================================
 */


#define SWAP(a,b) (a)^=(b)^=(a)^=(b)
#define CMP(a,b) ((a)>=(b)?1:0)

void sort(int array[], int len)
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (array[i] > array[j]) {
                SWAP(array[i],array[j]);
            }       
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

void show(int array[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ",array[i]);
    }
    printf("\n");

}
int main()
{
    int a[] = {10,10, 11,11, 9,9,30,30,32,8,6,51,4,19,25,99,49};
    sort(a, sizeof(a)/ sizeof(int));
    for (int i = 0; i < sizeof(a)/ sizeof(int); i++) {
        printf("%d ",a[i]);
    }
    printf("\n");

    int b[] = {2,5,3,5,4,3,4};
    int len = sizeof(b)/ sizeof(int);
    show(b, len);
    sort(b, sizeof(b)/ sizeof(int));
    show(b, len);

    int v = singleNumber(b, sizeof(b)/ sizeof(int));
    printf("v = %d\n", v);
	return 0;
}

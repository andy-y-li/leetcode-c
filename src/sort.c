/*
 * =====================================================================================
 *
 *       Filename:  sort.c
 *
 *    Description:  ºÚµ•µƒ≈≈–ÚÀ„∑®°£
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

int main()
{
    int a[] = {10,10, 11,11, 9,9,30,30,32,8,6,51,4,19,25,99,49};
    sort(a, sizeof(a)/ sizeof(int));
    for (int i = 0; i < sizeof(a)/ sizeof(int); i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
	return 0;
}

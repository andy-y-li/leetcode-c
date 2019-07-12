/*
 * =====================================================================================
 *
 *       Filename:  p013.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/19 13:08:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Andy (), andy_y_li@163.com
 *        Company:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int romanToInt(char * s)
{
    int total = 0;
    int arr[7] = {1,5,10,50,100,500,1000};
    int temp_last = -1;
    int temp = 0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i] == 'I')
        {
            temp = 0;
        }
        else if(s[i] == 'V')
        {
            temp = 1;
        }
        else if(s[i] == 'X')
        {
            temp = 2;
        }
        else if(s[i] == 'L')
        {
            temp = 3;
        }
        else if(s[i] == 'C')
        {
            temp = 4;
        }
        else if(s[i] == 'D')
        {
            temp = 5;
        }
        else if(s[i] == 'M')
        {
            temp = 6;
        }
        if(temp >= temp_last)
        {
            total += arr[temp];
            temp_last = temp;
        }
        else if(temp < temp_last)
        {
            total -= arr[temp];
            temp_last = temp;
        }
    }
    return total;
}

int main()
{
    char s[] = "MCMXCIV";
    int v = romanToInt(s);
    printf("v=%d\n",v);
    return 0;
}


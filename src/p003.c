/*
 * =====================================================================================
 *
 *       Filename:  p003.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/25/19 10:04:22
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


int lengthOfLongestSubstring(char * s){
    
    char flag[200];
    memset(flag, 0, 200);
    char *left = s;
    char *right = s;
    int index = 0;
    int maxLen = 0, curLen = 0;

    int len = strlen(s);

    if (len < 2) {
        return len;
    }

    while (right < s + len) {
	    index = (int )(*right);

	    if (1 == flag[index]) {
		    while (*left != *right) {
			    curLen--;
			    index =  (int )(*left);
			    flag[index] = 0;
			    left++;
		    }
		    left++;
	    } else {
		    curLen++;
		    flag[index] = 1;
	    }

	    if (curLen > maxLen) {
		    maxLen = curLen;
	    }

	    right++;
    }

    return maxLen;
}

int main()
{
    char *s = "adkdfgt";
    int l = lengthOfLongestSubstring(s);
    printf("max len:%d\n",l);
    return 0;
}


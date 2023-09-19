/*
 * String.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   abc
   z
   stuvwxyz
 * test case output
   cba
   z
   zyxwvuts
 */

#include <stdio.h>

void reverse(char s[], int len);


int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++) {
        char str[101];
        scanf("%s", str);
        int len = 0;
        while(str[len++] != 0) ;
        len--;
        reverse(str, len);
        printf("\n");
    }
    return 0;
}

void reverse(char s[], int len) {
    printf("%c", s[--len]);
    if (len>0) {
        reverse(s, len);
    }
}
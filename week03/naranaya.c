/*
 * naranaya.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   1 a
   9 cahfigedb
   26 zyxwvutsrqponmlkjihgfedcba
   
 * test case output
   a
   cahgbdefi
   abcdefghijklmnopqrstuvwxyz
 */

#include <stdio.h>

void swap(char *pt1, char *pt2);
void narayana(char *str, int len);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int len;
        scanf("%d", &len);
        char str[len];
        scanf("%s", str);
        narayana(str, len);
    }

    return 0;
}

void swap(char *pt1, char *pt2) {
    char tmp = *pt1;
    *pt1 = *pt2;
    *pt2 = tmp;
}

void narayana(char *str, int len) {
    int i = len - 1;
    while (i >= 1 && str[i-1] >= str[i]) {
        i--;
    }
    if (i == 0) {
        for(int t = len-1; t >= 0; t--) {
            printf("%c", str[t]);
        }
        printf("\n");
        return;
    }

    int j = len-1;
    while (j > i && str[i-1] > str[j]) {
        j--;
    }
    swap(&str[i-1], &str[j]);
    for(int t = 0; t < i; t++) {
        printf("%c", str[t]);
    }
    for(int t = len-1; t >= i; t--) {
        printf("%c", str[t]);
    }
    printf("\n");
}
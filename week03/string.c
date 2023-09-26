/*
 * string.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   abc
   z
   rstuvwxyz
 * test case output
   4
   1
   362880
 */

#include <stdio.h>
#include <string.h>

int result = 0;

void swap(char *pt1, char *pt2);
int weight(char s[]);
void permuteString(char *str, int begin, int end);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        result = 0;
        char str[10];
        scanf("%s", str);
        permuteString(str, 0, strlen(str));
        printf("%d\n", result);
    }
    return 0;
}

void swap(char *pt1, char *pt2) {
    char tmp = *pt1;
    *pt1 = *pt2;
    *pt2 = tmp;
}

int weight(char s[]) {
    int i = 0;
    int answer = 0;
    while(s[i] != '\0') {
        if (i%2 == 0) answer += s[i++] - 'a';
        else answer -= s[i++] - 'a';
    }
    return answer;
}

void permuteString(char *str, int begin, int end) {
    int i;
    int range = end - begin;
    if(range == 1) {
        if (weight(str) > 0) result++;
    }
    else {
        for(i = 0; i < range; i++) {
            swap(&str[begin], &str[begin+i]);
            permuteString(str, begin+1, end);
            swap(&str[begin], &str[begin+i]);
        }
    }
}
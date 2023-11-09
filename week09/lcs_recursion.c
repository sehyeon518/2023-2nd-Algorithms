/*
 * longest common subsequence recursion
 * test case input
   3
   abcbdab bdcaba
   a a
   abcd zyxw
 * test case output
   4
   1
   0
*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 11

int lcs(char str1[], int m, char str2[], int n);

int max(int a, int b) {
    if (a>b) return a;
    return b;
}
int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while(numTestCases--) {
        char str1[MAX_LEN], str2[MAX_LEN];
        scanf("%s %s", str1, str2);
        int m = strlen(str1);
        int n = strlen(str2);
        int answer = lcs(str1, m-1, str2, n-1);
        printf("%d\n", answer);
    }

    return 0;
}

int lcs(char str1[], int m, char str2[], int n) {
    if(m<0 || n<0)
        return 0;

    if(str1[m] == str2[n]) {
        return 1 + lcs(str1, m-1, str2, n-1);
    }

    return max(lcs(str1, m, str2, n-1), lcs(str1, m-1, str2, n));
}
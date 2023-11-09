/*
 * longest common subsequence memoization
 * test case input
   4
   abcbdab bdcaba
   abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
   a b
   abcdefghijklmnopqrstuvwxyz zyxwvutsrqponmlkjihgfedcba
 * test case output
   4
   26
   0
   1
*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

int L[MAX_LEN][MAX_LEN];

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
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                L[i][j] = -1;
            }
        }
        int answer = lcs(str1, m, str2, n);
        printf("%d\n", answer);
    }

    return 0;
}

int lcs(char str1[], int m, char str2[], int n) {
    if (m <= 0 || n <= 0)
        return 0;

    if (L[m][n] != -1)
        return L[m][n];

    if (str1[m-1] == str2[n-1]) {
        L[m][n] = 1 + lcs(str1, m-1, str2, n-1);
        return L[m][n];
    }

    L[m][n] = max(lcs(str1, m, str2, n-1), lcs(str1, m-1, str2, n));
    return L[m][n];    
}
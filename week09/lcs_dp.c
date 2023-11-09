/*
 * longest common subsequence dinamic programming
 * test case input
   4
   abcbdab bdcaba
   abcdefghijklmnopqrstuvwxyz abcdefghijklmnopqrstuvwxyz
   a b
   abcdefghijklmnopqrstuvwxyz zyxwvutsrqponmlkjihgfedcba
 * test case output
   4 bcab
   26 abcdefghijklmnopqrstuvwxyz
   0
   1 k
*/
#include <stdio.h>
#include <string.h>

#define MAX_LEN 101

int S[MAX_LEN][MAX_LEN];
int L[MAX_LEN][MAX_LEN];

int lcsL(char str1[], int m, char str2[], int n);
void printLCS(char str1[], int m, char str2[], int n);

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
                L[i][j] = 0;
                S[i][j] = 0;
            }
        }
        int answer = lcsL(str1, m, str2, n);
        // for(int i = 0; i <= m; i++) {
        //     for(int j = 0; j <= n; j++) {
        //         printf("%d ", S[i][j])
        //     }
        // }
        printf("%d ", answer);
        printLCS(str1, m, str2, n);
        printf("\n");
    }

    return 0;
}

int lcsL(char str1[], int m, char str2[], int n) {
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(str1[i-1] == str2[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                S[i][j] = 0;
            }
            else {
                L[i][j] = max(L[i][j-1], L[i-1][j]);
                if(L[i][j] == L[i][j-1])
                    S[i][j] = 1;
                else
                    S[i][j] = 2;
            }
        }
    }
    return L[m][n];
}

void printLCS(char str1[], int m, char str2[], int n) {
    if(m==0 || n==0)
        return;
    if(S[m][n] == 0) {
        printLCS(str1, m-1, str2, n-1);
        printf("%c", str1[m-1]);
    }
    else if(S[m][n] == 1) {
        printLCS(str1, m, str2, n-1);
    }
    else {
        printLCS(str1, m-1, str2, n);
    }
}
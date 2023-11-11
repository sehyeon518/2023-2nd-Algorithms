/*
 * chained matrix multiplication memoization
 * test case input
   3
   4
   20 2 30 12 8
   2
   2 3 4
   25
   4 5 4 4 3 8 10 7 9 8 3 10 11 4 9 11 7 6 5 3 4 5 5 6 3 3
 * test case output
   1232
   24
   2814
*/
#include <stdio.h>
#include <limits.h>

#define MAX_N 100

int d[MAX_N+1];
int table[MAX_N+1][MAX_N+1];
long long int multiplication(int i, int j);

int min(int a, int b) {
    if(a < b) return a;
    return b;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);

    while(numTestCases--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++) {
            scanf("%d", &d[i]);
            for(int j = 0; j <= n; j++)
                table[i][j] = -1;
        }
        long long answer = multiplication(1, n);
        printf("%lld\n", answer);
    }
    return 0;
}

long long int multiplication(int i, int j) {
    if (i == j) return 0;

    if (table[i][j] > 0)
        return table[i][j];

    long long int count = LLONG_MAX;
    for (int k = i; k < j; k++) {
        long long int tmp = multiplication(i, k) + multiplication(k + 1, j) + d[i-1] * d[k] * d[j];
        if (tmp < count)
            count = tmp;
    }
    table[i][j] = count;
    return count;
}
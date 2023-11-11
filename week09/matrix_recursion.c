/*
 * chained matrix multiplication
 * test case input
   3
   4 20 2 30 12 8
   2 2 3 4
   10 5 8 2 9 4 10 6 1 11 3 7
 * test case output
   1232
   24
   299
*/
#include <stdio.h>
#include <limits.h>

#define MAX_N 10

int d[MAX_N+1];
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
        }
        long long answer = multiplication(1, n);
        printf("%lld\n", answer);
    }
    return 0;
}

long long int multiplication(int i, int j) {
    if (i == j) return 0;

    long long int count = LLONG_MAX;
    for (int k = i; k < j; k++) {
        long long int tmp = multiplication(i, k) + multiplication(k + 1, j) + d[i-1] * d[k] * d[j];
        if (tmp < count)
            count = tmp;
    }
    return count;
}
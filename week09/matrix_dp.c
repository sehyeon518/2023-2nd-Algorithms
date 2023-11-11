/*
 * chained matrix multiplication dinamic programming
 * test case input
   3
   4
   20 2 30 12 8
   2
   2 3 4
   15
   10 10 4 6 7 7 3 9 3 3 7 4 9 8 3 6
 * test case output
   (M1((M2M3)M4))
   1232
   (M1M2)
   24
   ((M1(M2((M3(M4(M5M6)))((M7M8)(M9((M10M11)(M12(M13M14))))))))M15)
   1560
*/
#include <stdio.h>
#include <limits.h>

#define MAX_N 102

int d[MAX_N+1];
int diagonal[MAX_N+1][MAX_N+1];
int p[MAX_N+1][MAX_N+1];

long long int multiplication(int n);
void order(int i, int j);

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
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= n; j++) {
                diagonal[i][j] = 0;
                p[i][j] = 0;
            }
        }
        long long answer = multiplication(n+1);
        
        order(1, n);
        printf("\n");
        printf("%lld\n", answer);
    }
    return 0;
}

long long int multiplication(int n) {
    for(int l = 2; l < n; l++) {
        for(int i = 1; i <= n-l; i++) {
            int j = i + l - 1;
            diagonal[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int tmp = diagonal[i][k] + diagonal[k+1][j] + d[i-1]*d[k]*d[j];
                if(tmp < diagonal[i][j]) {
                    diagonal[i][j] = tmp;
                    p[i][j] = k;
                }
            }
        }
    }
    return diagonal[1][n-1];
}

void order(int i, int j) {
    if(i==j)
        printf("M%d", i);
    else {
        int k = p[i][j];
        printf("(");
        order(i, k);
        order(k+1, j);
        printf(")");
    }
}
/*
 * Euclid.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   132 36
   0 12
   132 1
 * test case output
   12
   12
   1
 */

#include <stdio.h>

void gcd(int a, int b);
int f(int a, int b);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        gcd(a, b);
    }
    return 0;
}

void gcd(int a, int b) {
    int answer = f(a, b);
    printf("%d\n", answer);
}

int f(int a, int b) {
    if(b==0) return a;
    return f(b, a%b);
}
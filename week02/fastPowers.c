/*
 * fastPowers.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   2 16
   2 0
   9 2147483647
 * test case output
   536
   1
   369
 */

#include <stdio.h>

void fastPowers(int a, int n);
int f(int x, int n);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++) {
        int num, pow;
        scanf("%d %d", &num, &pow);
        fastPowers(num, pow);
    }
}

void fastPowers(int a, int n) {
    int answer = f(a, n);
    printf("%d\n", answer);
}

int f(int x, int n) {
    int y;
    if(n==0) return 1;
    else if(n%2 == 1) {
      y = f(x, (n-1)/2);
      return x*y*y % 1000;
    }
    else {
      y = f(x, n/2);
      return y*y % 1000;
    }
}
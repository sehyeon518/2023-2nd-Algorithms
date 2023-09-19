/*
 * Factorial.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   0
   25
   1000
 * test case output
   1
   984
   472
 */

#include <stdio.h>

void factorial(int n);
int f(int n);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++) {
        int num;
        scanf("%d", &num);
        factorial(num);
    }
}

void factorial(int n) {
    int answer = f(n);
    printf("%d\n", answer % 1000);
}

int f(int n) {
    if(n<=1) return 1;
    else {
        int fn = n * f(n-1);
        while(fn % 10 == 0) {
            fn /= 10;
        }
        return fn % 100000;
    }
}
/*
 * Fibonacci.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   0
   28
   30
 * test case output
   0
   317811
   832040
 */

#include <stdio.h>

void fibonacci(int n);
int f(int n);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for(int i = 0; i < numTestCases; i++) {
        int num;
        scanf("%d", &num);
        fibonacci(num);
    }
}

void fibonacci(int n) {
    int answer = f(n);
    printf("%d\n", answer);
}

int f(int n) {
    if (n<=1) {
        return n;
    }
    return f(n-1) + f(n-2);
}
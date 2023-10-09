/*
 * findingMax.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   7 18 24 56 2 9 36 47
   9 9 8 7 6 5 4 3 2 1
   1 9
 * test case output
   56
   9
   9
 */

#include <stdio.h>

int recurMax(int a[], int left, int right);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int n;
        scanf("%d", &n);
        int array[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        int answer = recurMax(array, 0, n-1);
        printf("%d\n", answer);
    }
}

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int recurMax(int a[], int left, int right) {
    int half;

    if (left == right)
        return a[left];
    else {
        half = (left + right) / 2;
        return max(recurMax(a, left, half), recurMax(a, half+1, right));
    }
}
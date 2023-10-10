/*
 * findingMaxSub.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   14 4 -6 0 2 3 -4 1 3 0 -9 4 1 -3 2
   2 -1 1
   5 -1 -1 -1 -1 0
 * test case output
   5
   1
   0
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

int max(int a, int b, int c) {
    if (a >= b && a >= c) return a;
    else if (b >= c && b >= a) return b;
    else return c;
}

int recurMax(int a[], int left, int right) {
    int half;

    if (left == right)
        return a[left];
    
    half = (left + right) / 2;
    int leftSum = recurMax(a, left, half);
    int rightSum = recurMax(a, half+1, right);
    
    int tmp = 0;
    int leftMax = 0;
    for (int i = half; i > left - 1; i--) {
        tmp += a[i];
        if (tmp > leftMax) leftMax = tmp;
    }
    tmp = 0;
    int rightMax = 0;
    for (int i = half + 1; i <= right; i++) {
        tmp += a[i];
        if (tmp > rightMax) rightMax = tmp;
    }
    return max(rightMax + leftMax, leftSum, rightSum);
}
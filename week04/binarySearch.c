/*
 * findingMax.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   7 21
   2 5 9 14 21 23 29
   7 20
   2 5 9 14 21 23 29
   1 1
   1
 * test case output
   4
   -1
   0
 */

#include <stdio.h>

int binarySearch(int a[], int left, int right, int value);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int n, v;
        scanf("%d %d", &n, &v);
        int array[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        int answer = binarySearch(array, 0, n-1, v);
        printf("%d\n", answer);
    }
}

int binarySearch(int a[], int left, int right, int value) {
    int mid;

    if (left > right)
        return -1;
    else {
        mid = (left + right) / 2;
        if (a[mid] == value) return mid;
        else if (a[mid] > value)
            return binarySearch(a, left, mid-1, value);
        else
            return binarySearch(a, mid+1, right, value);
    }
}
/*
 * firstElement.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   15 4 5 4 3 8 9 2 2 4 5 1 2 1 8 0
   1 1
   5 5 4 3 2 1
 * test case output
   4
   1
   1
 */

#include <stdio.h>

int firstElement(int a[], int n);

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
        int answer = firstElement(array, n);
        printf("%d\n", answer);
    }
}

int firstElement(int a[], int n) {
    int lenMax = 0;
    int lenTmp;

    for (int i = 0; i < n;) {
        int p = a[i];
        lenTmp = 0;
        while (p <= a[i] && i < n) {
            i++;
            lenTmp++;
        }
        if (lenTmp > lenMax)
            lenMax = lenTmp;
    }
    return lenMax;
}
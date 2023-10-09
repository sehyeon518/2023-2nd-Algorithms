/*
 * kadane.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   14 4 -6 0 2 3 -4 1 3 0 -9 4 1 -3 2
   2 -1 1
   5 -1 -1 -1 -1 0
 * test case output
   5 3 4
   1 1 1
   0 -1 -1 
 */

#include <stdio.h>

int maxSubsequenceSum(int a[], int n, int *start, int *end);

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int start, end;
        int n;
        scanf("%d", &n);
        int array[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        int answer = maxSubsequenceSum(array, n, &start, &end);
        if (answer < 0) {
            printf("0 -1 -1\n");
        }
        else {
            printf("%d %d %d\n", answer, start, end);
        }
    }
    return 0;
}

int maxSubsequenceSum(int a[], int n, int *start, int *end) {
    int i, j;
    int maxSum = 0, thisSum = 0;
    *start = *end = -1;
    for(i = 0, j = 0; j < n; j++) {
        thisSum += a[j];
        if(thisSum > maxSum) {
            maxSum = thisSum;
            *start = i;
            *end = j;
        }
        else if(thisSum == maxSum && j-i < *end-*start) {
            *start = i;
            *end = j;
        }
        else if (thisSum < 0) {
            i = j+1;
            if(a[i] == 0) {
                i++;
                j++;
            }
            if(a[j] == 0) {
                j++;
            }
            thisSum = 0;
        }
    }
    return maxSum;
}
/*
 * Mergesort.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   8 1 2 3 4 5 6 7 8
   8 8 1 7 2 6 3 5 4
   1 5
 * test case output
   12
   16
   0
 */

#include <stdio.h>

void mergeSortIterative(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);

int answer;

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int n;
        scanf("%d", &n);
        answer = 0;
        int array[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        
        mergeSortIterative(array, 0, n-1);
        printf("%d\n", answer);        
    }
}

void mergeSortIterative(int a[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    mergeSortIterative(a, low, mid);
    mergeSortIterative(a, mid+1, high);
    merge(a, low, mid, high);
}

void merge(int a[], int low, int mid, int high) {  
    int i, j, k;
    int tmp[100];

    for (i = low; i <= high; i++)
        tmp[i] = a[i];

    i = k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (tmp[i] <= tmp[j])
            a[k++] = tmp[i++];
        else
            a[k++] = tmp[j++];
        answer++;
    }
    while (i <= mid)
        a[k++] = tmp[i++];
    while (j <= high)
        a[k++] = tmp[j++];
}
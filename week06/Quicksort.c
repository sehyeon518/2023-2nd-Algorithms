/*
 * Quicksort.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   8
   9 4 7 3 9 2 5 8 1 6
   40 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9
   30 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
   30 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
   30 19 14 30 25 13 29 5 20 2 12 18 24 9 21 6 26 16 4 22 1 28 17 10 7 23 15 3 27 11 8
   1000 9 9 9 9 ... <총 1000 개의 ‘9’> ... 9 9 9
   1000 1 2 3 4 ... <1 부터 1000 까지의 정수> ... 998 999 1000
   1000 1000 999 998 ... <1000 부터 1 까지의 정수> ... 4 3 2 1
 * test case output
   7 14 45 17 Hoare swap, Lomuto swap, Hoare 비교, Lomuto 비교
   100 39 278 780
   0 29 493 435
   15 254 508 435
   43 71 212 100
   4932 999 11862 499500
   0 999 501498 499500
   500 250999 501998 499500
 */

#include <stdio.h>

void quickhoare(int a[], int low, int high);
int hoare(int a[], int low, int high);
void quicklomuto(int a[], int low, int high);
int lomuto(int a[], int low, int high);

int swap_hoare, swap_lomuto, compare_hoare, compare_lomuto;

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int n;
        scanf("%d", &n);
        swap_hoare = swap_lomuto = compare_hoare = compare_lomuto = 0;
        int arrayA[n], arrayB[n];
        for(int i = 0; i < n; i++) {
            int t;
            scanf("%d", &t);
            arrayA[i] = t;
            arrayB[i] = t;
        }
        quickhoare(arrayA, 0, n-1);
        quicklomuto(arrayB, 0, n-1);
        printf("%d %d %d %d\n", swap_hoare, swap_lomuto, compare_hoare, compare_lomuto);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickhoare(int a[], int low, int high) {
    if (low >= high) return;
    int p = hoare(a, low, high);
    quickhoare(a, low, p);
    quickhoare(a, p+1, high);
}

int hoare(int a[], int low, int high) {
    int i, j;
    int pivot = a[low];
    i = low - 1;
    j = high + 1;

    while(1) {
        while(a[++i] < pivot) compare_hoare++;
        while(a[--j] > pivot) compare_hoare++;
        compare_hoare += 2;
        if (i < j) {
            swap(&a[i], &a[j]);
            swap_hoare++;
        }
        else {
            return j;
        }
    }
}

void quicklomuto(int a[], int low, int high) {
    if (low >= high) return;
    int p = lomuto(a, low, high);
    quicklomuto(a, low, p-1);
    quicklomuto(a, p+1, high);
}

int lomuto(int a[], int low, int high) {
    int i, j;
    int pivot = a[low];
    int pivotPos;
    j = low;
    for(i = low + 1; i <= high; i++) {
        compare_lomuto++;
        if(a[i] < pivot) {
            j++;
            swap(&a[i], &a[j]);
            swap_lomuto++;
        }
    }
    pivotPos = j;
    swap(&a[pivotPos], &a[low]);
    swap_lomuto++;
    return pivotPos;
}
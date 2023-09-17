/*
 * combSort.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   9 1 2 3 4 5 6 7 8 9
   9 9 8 7 6 5 4 3 2 1
   9 9 6 3 1 2 4 5 7 8
 * test case output
    29 0
    29 6
    37 7
 */

#include <stdio.h>

#define MAX_SIZE 1000

void combSort(int a[], int n);

int main()
{
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; ++i)
    {
        int num;
        int a[MAX_SIZE];
        scanf("%d", &num);
        for (int j = 0; j < num; j++)
            scanf("%d", &a[j]);
        combSort(a, num);
    }
    return 0;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* comb sort 함수 */
void combSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수

    int gap = n;
    double shrink = 1.3;
    int sorted = 0;

    // comb sort 알고리즘 구현
    while (!sorted) {
        gap /= shrink;
        if (gap <= 1) {
            gap = 1;
            sorted = 1;
        }
        for(int i = 0; i + gap < n; i++) {
            countCmpOps++;
            if(a[i] > a[i+gap]) {
                swap(&a[i], &a[i+gap]);
                countSwaps++;
                sorted = 0;
            }
        }
    }

    printf("%d %d\n", countCmpOps, countSwaps);
}
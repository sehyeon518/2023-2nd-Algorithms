/*
 * InsertionSort.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   9 1 2 3 4 5 6 7 8 9
   9 9 8 7 6 5 4 3 2 1
   9 9 6 3 1 2 4 5 7 8
 * test case output
   8 0
   36 36
   20 15
 */

#include <stdio.h>

#define MAX_SIZE 1000

void insertionSort(int a[], int n);

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
        insertionSort(a, num);
    }
    return 0;
}
/* Insertion Sort 함수 */
void insertionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수

    // insertion sort 알고리즘 구현
    for(int i = 1; i < n; i++) {
        for(int j = i; j > 0 ; j--) {
            countCmpOps++;
            if (a[j-1] > a[j]) {
                int t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
                countSwaps++;
            }
            else break;
        }
    }
    printf("%d %d\n", countCmpOps, countSwaps);
}
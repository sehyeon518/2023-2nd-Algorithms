/*
 * ShellSort.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   9 1 2 3 4 5 6 7 8 9
   9 9 8 7 6 5 4 3 2 1
   9 9 6 3 1 2 4 5 7 8
 * test case output
   20 0
   22 8
   23 7
 */

#include <stdio.h>

#define MAX_SIZE 1000

void ShellSort(int a[], int n);

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
        ShellSort(a, num);
    }
    return 0;
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
/* Shell Sort 함수 */
void ShellSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수

    int shrinkRatio = 2;
    int gap = n / shrinkRatio;
    // Shell sort 알고리즘 구현

    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int tmp = a[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                countCmpOps++;
                if (a[j-gap] > tmp) {
                    a[j] = a[j - gap];
                    countSwaps++;
                }
                else break;
            }
            a[j] = tmp;
        }
        gap /= shrinkRatio;
    }
    printf("%d %d\n", countCmpOps, countSwaps);
}
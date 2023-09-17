/*
 * SelectionSort.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   9 1 2 3 4 5 6 7 8 9
   9 9 8 7 6 5 4 3 2 1
   9 9 6 3 1 2 4 5 7 8
 * test case output
   36 0
   36 4
   36 7 
 */

#include <stdio.h>

#define MAX_SIZE 1000

void selectionSort(int a[], int n);

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

        selectionSort(a, num);
    }
    return 0;
}
/* Selection Sort 함수 */
void selectionSort(int a[], int n)
{
    int countCmpOps = 0; // 비교 연산자 실행 횟수
    int countSwaps = 0;  // swap 함수 실행 횟수
    
    // selection sort 알고리즘 구현
    for (int i = 0; i < n-1; i++) {
        int jMin = i;
        for(int j = i+1; j < n; j++) {
            if (a[j] < a[jMin]) {
                jMin = j;
            }
            countCmpOps++;
        }
        if(jMin != i) {
            int t = a[jMin];
            a[jMin] = a[i];
            a[i] = t;
            countSwaps++;
        }
    }
    printf("%d %d\n", countCmpOps, countSwaps);
}
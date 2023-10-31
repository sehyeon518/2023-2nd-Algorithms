/*
3
3 3 4 5
1 10
5 5 4 3 2 1
*/
/*
5 3 3
10 10 1
5 1 5
*/

#include <stdio.h>

int count_recursive_call; // 함수 FindMinMax를 재귀호출하는 횟수를 저장하는 전역변수

int maxelement(int a, int b) {
    if (a>b) return a;
    return b;
}
int minelement(int a, int b) {
    if (a<b) return a;
    return b;
}
void FindMinMax(int a[], int low, int high, int *max, int *min)
{
    count_recursive_call++;
    int min1, min2, max1, max2;
    // base case: 원소가 1개인 경우
    if (low == high)
    {
        *max = *min = a[low];
    }
    // base case: 원소가 2개인 경우
    else if (high-low == 1)
    {
        *max = maxelement(a[low], a[high]);
        *min = minelement(a[low], a[high]);
    }
    // recursive step: 원소가 2개 이상인 경우
    else
    {
        int mid = (low + high) / 2;
        FindMinMax(a, low, mid, &max1, &min1);
        FindMinMax(a, mid + 1, high, &max2, &min2);

        *max = maxelement(max1, max2);
        *min = minelement(min1, min2);
    }
}
int main()
{
    int num_test_cases;
    int data[100], size;
    scanf("%d", &num_test_cases); // 테스트 데이터 개수
    while (num_test_cases--)
    {
        scanf("%d", &size);       // 주어진 정수의 개수
        count_recursive_call = 0; // 재귀함수 호출횟수를 0으로 초기화
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &data[i]);
        }
        int min, max;
        FindMinMax(data, 0, size - 1, &max, &min);
        printf("%d %d %d\n", max, min, count_recursive_call);
    }
}
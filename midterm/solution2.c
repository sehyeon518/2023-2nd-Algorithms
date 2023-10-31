/*
3
15 5 3 4 4 2 3 3 8 7 3 5 4 5 8 9
1 1
5 5 4 3 2 1
*/
/*
4
1
1
*/

#include <stdio.h>

int maxarray(int a[], int n) {
    int maxLen = 0;
    int thisLen = 0;

    int i = 0;
    for(int j = i; j < n; j++) {
        if(j > 0 && a[j-1] <= a[j]) {
            thisLen++;
        }
        else {
            i = j;
            thisLen = 1;
        }
        if(thisLen > maxLen)
            maxLen = thisLen;
    }
    return maxLen;
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);
    while (num_test_cases--) {
        int n;
        scanf("%d", &n);
        int array[n];
        for(int i = 0; i < n; i++) {
            scanf("%d", &array[i]);
        }
        int answer = maxarray(array, n);
        printf("%d\n", answer);
    }
}
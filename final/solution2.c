#include <stdio.h>
#include <stdlib.h>

#define MAX_N 101

typedef struct {
    int c, p;
} cheese;

int compare(const void * a, const void *b) {
    if(((cheese *)a)->c == ((cheese *)b)->c) {
        return ((cheese *)a)->p - ((cheese *)b)->p;
    }
    return ((cheese *)b)->c -((cheese *)a)->c;
}

int max(int a, int b) {
    if(a > b) return a;
    return b;
}

int greedy(int n, int w, cheese array[], int index) {
    if (index >= n) return 0;
    if (w - array[index].c <= 0) return 0;

    int a = greedy(n, w - array[index].c, array, index+1) + array[index].p;
    int b = greedy(n, w, array, index+1);
    return max(a, b);
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while(numTestCases--) {
        int n, W;
        scanf("%d %d", &n, &W);
        cheese *array = malloc(sizeof(cheese) * n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &array[i].p, &array[i].c);
        }
        qsort(array, n, sizeof(cheese), compare);
        
        int answer = greedy(n, W, array, 0);
        free(array);
        printf("%d\n", answer);
    }
}
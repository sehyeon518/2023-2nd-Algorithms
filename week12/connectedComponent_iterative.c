/*
 * connectedComponent_iterative.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   9 1 1 3 2 1 3 3 3 1 2 7 4 0 5 1 6 6 1 5 7 3 3 8 9 8 2 7 9 9 2 7 8
   3 1 0 2 0 3 0
   3 1 2 2 3 2 2 1 3 3 2 1 2
 * test case output
   3 1 2 6
   3 1 1 1
   1 3
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001

void connected_component(int n);

int graph[MAX_N][MAX_N];
int visited[MAX_N];

void init_graph(int n) {
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while(numTestCases--) {
        int n;
        scanf("%d", &n);

        init_graph(n);

        for(int i = 1; i <= n; i++) {
            int tmp;
            scanf("%d", &tmp);
            int neighbors;
            scanf("%d", &neighbors);
            while(neighbors--) {
                int neighbor;
                scanf("%d", &neighbor);
                graph[i][neighbor] = 1;
            }
        }

        connected_component(n);
    }
}

void dfs(int i, int n, int *size_tmp) {
    int stack[MAX_N];
    int top = 0;

    stack[top] = i;
    visited[i] = 1;

    while(top >= 0) {
        int tmp_node = stack[top--];

        for(int neighbor = 1; neighbor <= n; neighbor++) {
            // 아직 방문하지 않은 이웃
            if(graph[tmp_node][neighbor] == 1 && visited[neighbor] == 0) {
                stack[++top] = neighbor;
                visited[neighbor] = 1;
                (*size_tmp)++;
            }
        }
    }
}

void connected_component(int n) {
    int size[n+1]; // connected component 원소 개수
    int count = 0; // connected component 개수

    for(int i = 1; i <= n; i++) {
        if(visited[i] == 0) {
            int size_tmp = 1;
            dfs(i, n, &size_tmp);

            size[count++] = size_tmp;
        }
    }

    printf("%d ", count);
    qsort(size, count, sizeof(int), compare);
    for(int i = 0; i < count; i++) {
        printf("%d ", size[i]);
    }
    printf("\n");
}
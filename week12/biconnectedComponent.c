/*
 * biconnectedComponent.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   4
   11 1 1 3 2 1 3 3 4 1 2 4 5 4 1 3 5 3 3 6 7 6 2 5 8 7 2 5 8 8 3 6 7 9 9 3 8 10 11 10 2 9 11 11 2 9 10
   5 1 1 2 2 2 1 3 3 2 2 4 4 2 3 5 5 1 4
   6 1 5 2 3 4 5 6 2 1 1 3 1 1 4 1 1 5 1 1 6 1 1
   6 1 2 2 6 2 2 1 3 3 2 2 4 4 2 3 5 5 2 4 6 6 2 5 1
 * test case output
   7 4 3 5 8 9
   4 3 2 3 4
   5 1 1
   1 0
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1001

void biconnected_component(int n);

int numBicomponents;
int numCutPoints;
int visited[MAX_N];
int graph[MAX_N][MAX_N];
int back[MAX_N];
int dfsNumber[MAX_N];
int dfsOrder;
int cutPoints[MAX_N];
int isTrueCutPoint = 0;

void init_graph(int n) {
    dfsOrder = 1;
    numBicomponents = 1;
    numCutPoints = 0;
    isTrueCutPoint = 0;
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        back[i] = INT_MAX;
        dfsNumber[i] = 0;
        for(int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

int min(int a, int b) {
    return a<b?a:b;
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

        biconnected_component(n);
    }
}

void dfs(int v, int n) {
    int isCutPoint = 0;
    for(int w = 1; w <= n; w++) {
        if(graph[v][w] == 0) // 현재 node와 연결되어 있지 않은 경우
            continue;
        
        if(dfsNumber[w]) {
            back[v] = min(back[v], dfsNumber[w]);
        }
        else {
            dfsNumber[w] = dfsOrder++;
            dfs(w, n);
            if(v!=1 && back[w] >= dfsNumber[v]) {
                isCutPoint = 1;
                numBicomponents++;
            }
            else if(v==1 && back[w] >= dfsNumber[v]) {
                if(isTrueCutPoint) {
                    isCutPoint = 1;
                    numBicomponents++;
                }
                else {
                    isCutPoint = 0;
                    isTrueCutPoint = 1;
                }
            }
            else {
                back[v] = min(back[v], back[w]);
            }
        }
    }
    if(isCutPoint) {
        cutPoints[numCutPoints++] = v;
    }
}

void biconnected_component(int n) {
    for(int i = 1; i <= n; i++) {
        if (!dfsNumber[i]) {
            dfsNumber[i] = dfsOrder++;
            dfs(i, n);
        }
    }

    printf("%d\n", numBicomponents);
    qsort(cutPoints, numCutPoints, sizeof(int), compare);
    printf("%d ", numCutPoints);
    for(int i = 0; i < numCutPoints; i++) {
        printf("%d ", cutPoints[i]);
    }
    printf("\n");
}
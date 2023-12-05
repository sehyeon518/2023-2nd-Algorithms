/*
 * mst_kruskal.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   10
   1 3 2 9 3 8 4 5
   2 3 1 9 5 7 6 9
   3 5 1 8 4 3 5 2 7 3 8 5
   4 3 1 5 3 3 8 7
   5 4 2 7 3 2 6 5 7 4
   6 5 2 9 5 5 7 6 9 9 10 8
   7 5 3 3 5 4 6 6 8 4 9 7
   8 4 3 5 4 7 7 4 9 4
   9 4 6 9 7 7 8 4 10 3
   10 2 6 8 9 3
   5
   1 3 2 1 4 8 5 5
   2 2 1 1 3 6
   3 1 2 6
   4 1 1 8
   5 1 1 5
   5
   1 4 2 20 3 12 4 12 5 8
   2 3 1 20 3 17 4 5
   3 3 1 12 2 17 5 6
   4 3 1 12 2 5 5 5
   5 3 1 8 3 6 4 5
 * test case output
   36
   20
   24
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 1001

int edges[MAX_N][MAX_N];
int visited[MAX_N];

int prim(int n);

void init_graph(int n) {
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
        for(int j = 1; j <= n; j++) {
            edges[i][j] = INT_MAX;
        }
    }
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while (numTestCases--) {
        int n;
        scanf("%d", &n);
        init_graph(n);
        for(int i = 1; i <= n; i++) {
            int k, m;
            scanf("%d %d", &k, &m);
            while(m--) {
                int v, w;
                scanf("%d %d", &v, &w);
                edges[k][v] = w;
            }
        }
        int answer = prim(n);
        printf("%d\n", answer);
    }
}

int prim(int n) {
    int answer = 0;

    int nearest[n+1];
    int distance[n+1];
    
    for(int i = 2; i <= n; i++) {
        nearest[i] = 1;
        distance[i] = edges[1][i];
    }

    nearest[1] = 0;
    
    visited[1] = 1;

    while(1) {
        int min_dist = INT_MAX;
        int u = -1;
        for(int i = 1; i <= n; i++) {
            if(!visited[i] && distance[i] < min_dist) {
                u = i;
                min_dist = distance[i];
            }
        }

        if(u == -1) break;

        visited[u] = 1;
        answer += min_dist;

        for (int v = 1; v <= n; v++) {
            if (!visited[v] && edges[u][v] < distance[v]) {
                distance[v] = edges[u][v];
                nearest[v] = u;
            }
        }
    }

    return answer;
}
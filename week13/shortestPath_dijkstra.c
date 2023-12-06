/*
 * shortestPath_dijkstra.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   10
   1 2 2 9 3 8 2 2 5 7 6 9 3 2 7 3 8 5 4 2 1 5 3 3 5 2 3 2 6 5 6 2 9 9 10 8 7 4 5 4 6 6 8 4 9 7 8 2 4 7 9 4 9 1 10 3 10 0
   10
   1 1 10 94 2 1 4 21 3 1 5 38 4 0 5 1 8 75 6 0 7 1 2 64 8 1 9 56 9 0 10 3 3 94 6 1 7 19
   10
   1 4 2 20 4 32 5 84 9 34 2 1 3 12 3 4 5 87 8 80 9 49 10 61 4 1 5 4 5 3 3 99 6 54 7 35 6 1 7 45 7 3 1 87 5 67 10 39 8 3 4 93 5 55 9 61 9 0 10 5 1 29 2 11 4 23 7 38 8 4
 * test case output
   49
   462
   256
*/

#include <stdio.h>
#include <limits.h>

#define MAX_N 1001

int edges[MAX_N][MAX_N];

int dijkstra(int n);

void init_graph(int n) {
    for(int i = 1; i <= n; i++) {
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
        int answer = dijkstra(n);
        printf("%d\n", answer);
    }
}

void print_array(int n, int array[]) {
	for(int i = 1; i <= n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

int dijkstra(int n) {
    int nearest[MAX_N];
    int distance[MAX_N];
    int add[MAX_N];
    int answer = 0;

    for (int i = 2; i <= n; i++) {
        nearest[i] = 1;
        add[i] = distance[i] = (edges[1][i] == INT_MAX) ? INT_MAX : edges[1][i];
    }
    distance[1] = 0;

    for (int k = 0; k < n; k++) {
        int min = INT_MAX;
        int vnear = -1;

        for (int i = 2; i <= n; i++) {
            if (distance[i] >= 0 && distance[i] < INT_MAX && distance[i] < min) {
                min = distance[i];
                vnear = i;
            }
        }
        min = add[vnear];

        if (vnear != -1) {
            int disttmp = distance[vnear];
            distance[vnear] = -1;
            answer += min;

            for (int i = 2; i <= n; i++) {
                if (distance[i] >= 0 && edges[vnear][i] < INT_MAX && disttmp + edges[vnear][i] < distance[i]) {
                    distance[i] = edges[vnear][i] + disttmp;
                    add[i] = edges[vnear][i];
                    nearest[i] = vnear;
                }
            }
        }
		else {
			break;
		}
    }

    return answer;
}
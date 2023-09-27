/*
 * knightTour.c
 * 소프트웨어학부 20213043 이세현
 * test case input
   3
   6 8 3 4
   6 5 1 2
   4 4 1 2
 */

#include <stdio.h>

typedef struct Point {
    int x, y;
} point;

point d[8] = {{1,2},{1,-2},{-1,2},{-1,-2},
              {2,1},{2,-1},{-2,1},{-2,-1}};

int M, N;
int board[9][9], path[9][9];

int p;

int knightTour(point pos, int counter) {
    point next;

    if(counter == M * N) {
        return 1;
    }
    for(int i = 0; i < 8; i++) {
        next.x = pos.x + d[i].x;
        next.y = pos.y + d[i].y;
        if (next.x > 0 && next.x <= M && next.y > 0 && next.y <= N && board[next.x][next.y] == 0) {
            board[next.x][next.y] = 1;
            path[next.x][next.y] = counter+1;
            if (knightTour(next, counter+1)) {
                return 1;
            }
            board[next.x][next.y] = 0;
        }
    }
    return 0;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    for (int i = 0; i < numTestCases; i++) {
        int s, t;
        scanf("%d%d%d%d", &M, &N, &s, &t);
        p = M * N;
        for(int m = 1; m <= M; m++) {
            for(int n = 1; n <= N; n++) {
                board[m][n] = 0;
                path[m][n] = -1;
            }
        }
        path[s][t] = 1;
        board[s][t] = 1;
        int complete = knightTour((point){s, t}, 1);
        if (!complete) printf("0\n");
        else {
            printf("1\n");
            for(int m = 1; m <= M; m++) {
                for(int n = 1; n <= N; n++) {
                    printf("%d ", path[m][n]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
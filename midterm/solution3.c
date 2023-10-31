/*
3
11 4 5 6 11 10 9 2 8 3 7 1
5 1 2 3 4 5
7 5 7 2 6 3 1 4
*/
/*
4
5
1
*/

#include <stdio.h>

int visited[101] = {0};

int teamcount = 0;

void solution(int note[], int start, int n) {
    visited[n] = 1;
    if(start == n) {
        teamcount++;
        return;
    }
    solution(note, start, note[n]);
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while(numTestCases--) {
        teamcount = 0;
        int n;
        scanf("%d", &n);
        int note[n+1];
        for(int i = 1; i <= n; i++) {
            scanf("%d", &note[i]);
            visited[i] = 0;
        }
        for(int i = 1; i <= n; i++) {
            if(visited[i] == 0)
                solution(note, i, note[i]);
        }
        printf("%d\n", teamcount);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 101

int s[MAX_N];
int t[MAX_N];

typedef struct {
    int s, t;
} meeting;

int compare(const void *a, const void *b) {
    return ((meeting *)a)->t - ((meeting *)b)->t;
}

int solution(int n) {
    int answer = 1;
    meeting *meetings = malloc(sizeof(meeting) * n);
    for(int i = 0; i < n; i++) {
        meetings[i].s = s[i];
        meetings[i].t = t[i];
    }
    qsort(meetings, n, sizeof(meeting), compare);
    int finish = meetings[0].t;
    
    for(int tmp = 1; tmp < n; tmp++) {
        if(meetings[tmp].s <= finish) continue;

        answer++;
        finish = meetings[tmp].t;
    }
    return answer;
}

int main() {
    int numTestCases;
    scanf("%d", &numTestCases);
    while(numTestCases--) {
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d %d", &s[i], &t[i]);
        }
        int answer = solution(n);
        printf("%d\n", answer);
    }
}
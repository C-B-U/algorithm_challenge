#include <stdio.h>

int N, M;
int visited[9];

void dfs(int sequence[], int length) {
    if (length == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", sequence[i]);
        }
        printf("\n");
        return;
    }

    for (int num = 1; num <= N; num++) {
        if (!visited[num]) {
            sequence[length] = num;
            visited[num] = 1;
            dfs(sequence, length + 1);
            visited[num] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);

    int sequence[10];
    dfs(sequence, 0);

    return 0;
}
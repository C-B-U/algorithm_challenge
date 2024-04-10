#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int map[5][5];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};
int v[1000000]; // 임의의 충분히 큰 크기로 설정

void DFS(int y, int x, int num, int cnt) {
    if (cnt == 6) {
        v[num] = 1;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= 5 || nx >= 5)
            continue;

        DFS(ny, nx, num * 10 + map[ny][nx], cnt + 1);
    }
}

int main() {
    // 입력
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    // 모든 좌표의 DFS 경로 탐색
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            DFS(i, j, 0, 0);
        }
    }

    // 중복 원소 제거 및 개수 계산
    int count = 0;
    for (int i = 0; i < 1000000; i++) {
        if (v[i] == 1)
            count++;
    }

    // 정답 출력
    printf("%d\n", count);

    return 0;
}

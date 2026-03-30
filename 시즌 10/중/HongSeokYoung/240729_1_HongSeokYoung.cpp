#include <stdio.h>

int n, m;
int A[50][50], B[50][50];

// 3x3 행렬 뒤집기 함수
void flip(int x, int y) {
    for (int i = x; i < x + 3; i++) {
        for (int j = y; j < y + 3; j++) {
            A[i][j] = !A[i][j];  // 0을 1로, 1을 0으로 변환
        }
    }
}

// 행렬 비교 함수
int isEqual() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] != B[i][j]) return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d %d", &n, &m);

    // 행렬 A 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &A[i][j]);
        }
    }

    // 행렬 B 입력
    for (int i = 0; i < n; i++) {  // 수정된 부분
        for (int j = 0; j < m; j++) {
            scanf("%1d", &B[i][j]);
        }
    }

    int count = 0;
    // 3x3 뒤집기를 적용할 수 있는 모든 위치에서 검사
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (A[i][j] != B[i][j]) {  // 다른 경우에만 flip
                flip(i, j);
                count++;
            }
        }
    }

    // 결과 확인
    if (isEqual()) {
        printf("%d\n", count);
    } else {
        printf("-1\n");
    }

    return 0;
}
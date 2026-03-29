#include <stdio.h>
#include <stdlib.h>

void getErrors(char start, int offsetX, int offsetY, char** board, int** error) {
    // char start = 'W';
    // int offsetX = 0, offsetY = 0;
    for (int i = 0 + offsetX; i < 8 + offsetX; i = i + 2) {
        for (int j = 0 + offsetY; j < 8 + offsetY; j = j + 2) {
            if (board[i][j] != start) {
                error[offsetX][offsetY] += 1;
            }
        }
        for (int j = 1 + offsetY; j < 8 + offsetY; j = j + 2) {
            if (board[i][j] == start) {
                error[offsetX][offsetY] += 1;
            }
        }
    }
    for (int i = 1 + offsetX; i < 8 + offsetX; i = i + 2) {
        for (int j = 0 + offsetY; j < 8 + offsetY; j = j + 2) {
            if (board[i][j] == start) {
                error[offsetX][offsetY] += 1;
            }
        }
        for (int j = 1 + offsetY; j < 8 + offsetY; j = j + 2) {
            if (board[i][j] != start) {
                error[offsetX][offsetY] += 1;
            }
        }
    }
}

int main() {
    int m, n;
    char** board;
    int** error;
    scanf("%d %d", &m, &n);
    board = (char**)malloc(sizeof(char*) * m);

    for (int i = 0; i < m; i++) {
        board[i] = (char*)malloc(sizeof(char) * n);
        for (int j = 0; j < n; j++) {
            scanf(" %c", &board[i][j]);
        }
    }

    int result = 0b01111111111111111111111111111111;
    error = (int**)malloc(sizeof(int*) * (m-7));
    for (int i = 0; i < m-7; i++) {
        error[i] = (int*)malloc(sizeof(int) * (n - 7));
        for (int j = 0; j < n-7; j++) {
            char start = 'B';
            if (i%2 == j%2) {
                start = 'W';
            }
            getErrors(start, i, j, board, error);
            if (result > error[i][j]) {
                result = error[i][j];
            }
            if (result > 64-error[i][j]) {
                result = 64-error[i][j];
            }
        }
    }

    printf("%d", result);

    return 0;
}

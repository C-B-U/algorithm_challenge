#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 300
#define MAX_M 300

char grid[MAX_N * 3 + 1][MAX_M * 3 + 1];

void repair_block(int N, int M, int y, int x) {
    int center_y = y * 3 + 1;
    int center_x = x * 3 + 1;
    int checked = 0;

    if (x > 0) {
        char left = grid[center_y][center_x - 2];
        if (left == '#') {
            grid[center_y][center_x - 1] = '#';
            checked = 1;
        }
    }

    if (x < M - 1) {
        char right = grid[center_y][center_x + 2];
        if (right == '#') {
            grid[center_y][center_x + 1] = '#';
            checked = 1;
        }
    }

    if (y > 0) {
        char up = grid[center_y - 2][center_x];
        if (up == '#') {
            grid[center_y - 1][center_x] = '#';
            checked = 1;
        }
    }

    if (y < N - 1) {
        char down = grid[center_y + 2][center_x];
        if (down == '#') {
            grid[center_y + 1][center_x] = '#';
            checked = 1;
        }
    }

    if (checked) grid[center_y][center_x] = '#';
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N * 3; i++) {
        scanf("%s", grid[i]);
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            repair_block(N, M, y, x);
        }
    }

    for (int i = 0; i < N * 3; i++) {
        printf("%s\n", grid[i]);
    }

    return 0;
}
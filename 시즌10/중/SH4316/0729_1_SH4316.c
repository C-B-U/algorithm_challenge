#include <stdio.h>
#include <stdlib.h>

void flip(char** matrix, int x, int y) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[x+i][y+j] == '1') {
                matrix[x+i][y+j] = '0';
            }
            else {
                matrix[x+i][y+j] = '1';
            }
        }
    }
}

int main() {
    int n, m;
    int count = 0;
    char** matrix;
    scanf("%d %d" ,&n, &m);

    matrix = (char**)malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++) {
        matrix[i] = (char*)malloc(sizeof(char) * m);
        for (int j = 0; j < m; j++) {
            scanf(" %c", matrix[i] + j);
        }
    }

    char c;
    int i;
    for (i = 0; i < n-2; i++) {
        int j;
        for (j = 0; j < m-2; j++) {
            scanf(" %c", &c);
            if (matrix[i][j] != c) {
                flip(matrix, i, j);
                count++;
            }
        }
        for (; j < m; j++) {
            scanf(" %c", &c);
            if (matrix[i][j] != c) {
                printf("-1");
                return 0;
            }
        }
    }
    for (; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf(" %c", &c);
            if (matrix[i][j] != c) {
                printf("-1");
                return 0;
            }
        }
    }

    printf("%d", count);

    return 0;
}

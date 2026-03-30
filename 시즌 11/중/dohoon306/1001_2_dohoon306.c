#include<stdio.h>
#include<stdlib.h>

int main() {
    int row, col;
    char up, down, left, right;
    scanf("%d %d", &row, &col);

    char** array;
    array = (char**)malloc(row * 3 * sizeof(char*));
    for (int i = 0; i < row * 3; i++) {
        array[i] = (char*)malloc(col * 3 * sizeof(char));
    }

    for (int i = 0; i < row * 3; i++) {
        for (int j = 0; j < col * 3; j++) {
            scanf(" %c", &array[i][j]);
        }
    }

    for (int i = 0; i < row * 3; i += 3) {
        for (int j = 0; j < col * 3; j += 3) {
            left = array[i + 1][j];
            right = array[i + 1][j + 2];
            up = array[i][j + 1];
            down = array[i + 2][j + 1];
            array[i + 1][j + 1] = '#';

            if (j > 0 && array[i + 1][j - 1] == '#') {  // left
                array[i + 1][j] = '#';
            }
            if (j + 3 < col * 3 && array[i + 1][j + 3] == '#') {  // right
                array[i + 1][j + 2] = '#';
            }
            if (i > 0 && array[i - 1][j + 1] == '#') {  // up
                array[i][j + 1] = '#';
            }
            if (i + 3 < row * 3 && array[i + 3][j + 1] == '#') {  // down
                array[i + 2][j + 1] = '#';
            }
        }
    }


    for (int i = 0; i < row * 3; i++) {
        for (int j = 0; j < col * 3; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < row * 3; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

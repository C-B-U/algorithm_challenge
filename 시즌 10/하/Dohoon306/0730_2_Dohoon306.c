#include<stdio.h>
#include<stdlib.h>
#define SIZE 101

int main() {
    int num, ** arr, first, second, size = 0;
    scanf("%d", &num);
    arr = (int**)malloc((SIZE) * sizeof(int*));
    for (int i = 0; i <= SIZE-1; i++) {
        arr[i] = (int*)malloc((SIZE) * sizeof(int));
    }
    for (int i = 0; i <= SIZE-1; i++) {
        for (int j = 0; j <= SIZE-1; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &first, &second);
        for (int j = first; j <= first + 9; j++) {
            for (int k = second; k <= second + 9; k++) {
                arr[j][k] = 1;
            }
        }
    }
    for (int i = 0; i <= SIZE-1; i++) {
        for (int j = 0; j <= SIZE-1; j++) {
            if (arr[i][j] == 1) {
                size++;
            }
        }
    }
    printf("%d\n", size);
}

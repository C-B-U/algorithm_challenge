#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char i;
    char j;
    char k;
} Coordinate;

typedef struct {
    const int limit;
    int head;
    int tail;
    Coordinate *arr;
} Queue;

int main() {
    int M, N, H;
    scanf("%d %d %d", &M, &N, &H);

    signed char ***arr = malloc(H * sizeof(signed char**));
    for(int i = 0; i < H; i++) {
        arr[i] = malloc(N * sizeof(signed char*));
        for(int j = 0; j < N; j++) {
            arr[i][j] = malloc(M * sizeof(signed char));
        }
    }

    Queue queue =  { M * N * H, 0, 0, malloc(M * N * H * sizeof(Coordinate)) };

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                scanf("%hhd", &arr[i][j][k]);
                if(arr[i][j][k] == 1) {
                    queue.arr[queue.tail++] = (Coordinate){ i, j, k };
                }
            }
        }
    }

    int date;

    for(date = 0; queue.head < queue.tail; date++) {
        int last = queue.tail;
        for(int l = queue.head; l < last; l++) {
            int i = queue.arr[l].i;
            int j = queue.arr[l].j;
            int k = queue.arr[l].k;

            if(i != 0 && arr[i - 1][j][k] == 0) {
                arr[i - 1][j][k] = 1;
                queue.arr[queue.tail++] = (Coordinate){ i - 1, j, k };
            }

            if(j != 0 && arr[i][j - 1][k] == 0) {
                arr[i][j - 1][k] = 1;
                queue.arr[queue.tail++] = (Coordinate){ i, j - 1, k };
            }

            if(k != 0 && arr[i][j][k - 1] == 0) {
                arr[i][j][k - 1] = 1;
                queue.arr[queue.tail++] = (Coordinate){ i, j, k - 1 };
            }

            if(i != H - 1 && arr[i + 1][j][k] == 0) {
                arr[i + 1][j][k] = 1;
                queue.arr[queue.tail++] = (Coordinate){ i + 1, j, k };
            }

            if(j != N - 1 && arr[i][j + 1][k] == 0) {
                arr[i][j + 1][k] = 1;
                queue.arr[queue.tail++] = (Coordinate){ i, j + 1, k };
            }

            if(k != M - 1 && arr[i][j][k + 1] == 0) {
                arr[i][j][k + 1] = 1;
                queue.arr[queue.tail++] = (Coordinate){ i, j, k + 1 };
            }
        }
        queue.head = last;
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(arr[i][j][k] == 0) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    printf("%d", date - 1);

    return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, M;
    scanf("%d", &N);

    int* crane = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &crane[i]);
    }

    scanf("%d", &M);

    int* box = (int*)malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        scanf("%d", &box[i]);
    }

    bubble_sort(crane, N);
    bubble_sort(box, M);

    int count = 0;

    if (crane[N - 1] < box[M - 1]) {
        printf("-1");
        free(crane);
        free(box);
        return 0;
    }

    while (M > 0) {
        count++;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = M - 1; j >= 0; j--) {
                if (crane[i] >= box[j]) {
                    for (int k = j; k < M - 1; k++) {
                        box[k] = box[k + 1];
                    }
                    M--;
                    break;
                }
            }
        }
    }

    printf("%d", count);

    free(crane);
    free(box);
    return 0;
}
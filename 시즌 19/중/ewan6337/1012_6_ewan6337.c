#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int));
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = 0;

    for(int i = N - 1; i >= 0; i--) {
        if(arr[i - 1] > arr[i]) {
            arr[i - 1] = arr[i];
            answer++;
        }
    }

    printf("%d\n", answer);
    for(int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

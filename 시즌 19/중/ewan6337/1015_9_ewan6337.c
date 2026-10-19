#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int recursive(int N, int *arr, int num);

int main() {
    int N;
    scanf("%d", &N);

    int *arr = calloc(N, sizeof(int));

    int answer = 0;
    for(int i = 0; i < N; i++) {
        arr[0] = i;
        answer += recursive(N, arr, 1);
    }

    printf("%d", answer);

    return 0;
}

int recursive(int N, int *arr, int num) {
    if(num == N) {
        return 1;
    }

    int return_value = 0;
    bool is_able;

    for(int i = 0; i < N; i++) {
        is_able = true;
        for(int j = 0; j < num; j++) {
            if(arr[j] == i || num - j == abs(i - arr[j])) {
                is_able = false;
                break;
            }
        }

        if(is_able) {
            arr[num] = i;
            return_value += recursive(N, arr, num + 1);
        }
    }

    return return_value;
}

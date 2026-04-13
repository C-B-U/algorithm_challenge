#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int arr[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0;

    for(int i = 0; i < K; i++) {
        sum += arr[i];
    }

    int max = sum;

    for(int i = K; i < N; i++) {
        sum = sum - arr[i - K] + arr[i];
        if(sum > max) {
            max = sum;
        }
    }

    printf("%d\n", max);

    return 0;
}

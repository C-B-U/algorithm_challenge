// 알고리즘 챌린지17 6일차 문제

#include <stdio.h>
int arr[500005];

int main() {
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int current_sum = 0;
    int max_sum = 0;

    for (int i = 0; i < k; i++) {
        current_sum += arr[i % n];
    }
    max_sum = current_sum;

    for (int i = 1; i < n; i++) {
        current_sum = current_sum - arr[i - 1] + arr[(i + k - 1) % n];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    printf("%d\n", max_sum);
    return 0;
}
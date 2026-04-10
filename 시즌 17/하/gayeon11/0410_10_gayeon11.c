// 알고리즘 챌린지17 10일차 문제

#include <stdio.h>

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    int k = n - m + 2;

    for (int i = 0; i < k - 1; i++) {
        printf("%d %d\n", i, i + 1);
    }

    for (int i = k; i < n; i++) {
        printf("1 %d\n", i);
    }

    return 0;
}
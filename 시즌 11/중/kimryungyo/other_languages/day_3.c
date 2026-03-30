#include <stdio.h>

int main() {
    int N, K, A, B;
    scanf("%d %d %d %d", &N, &K, &A, &B);

    int pots[N];
    for (int i = 0; i < N; i++) {
        pots[i] = K;
    }

    int day = 0;
    int idx = 0;
    while (1) {
        day += 1;

        for (int i = idx; i < idx + A; i++) {
            pots[i] += B;
        }

        for (int i = 0; i < N; i++) {
            pots[i] -= 1;
            if (pots[i] == 0) {
                printf("%d\n", day);
                return 0;
            }
        }

        idx += A;
        if (idx == N) {
            idx = 0;
        }
    }

    return 0;
}
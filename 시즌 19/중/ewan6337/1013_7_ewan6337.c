#include <stdio.h>
#include <stdarg.h>

static inline int min2(int a, int b);

int main() {
    int N;
    scanf("%d", &N);

    int arr[3];
    int R = 0, G = 0, B = 0;
    int nR, nG, nB;

    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", arr, arr + 1, arr + 2);

        nR = arr[0] + min2(G, B);
        nG = arr[1] + min2(R, B);
        nB = arr[2] + min2(R, G);

        R = nR;
        G = nG;
        B = nB;
    }

    printf("%d", min2(R, min2(G, B)));
}

static inline int min2(int a, int b) {
    return a < b ? a : b;
}

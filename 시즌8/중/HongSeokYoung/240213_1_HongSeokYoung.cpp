#include <stdio.h>

int memo[41][2];

int fibonacci(int n, int flag) {
    if (memo[n][flag] != -1) {
        return memo[n][flag];
    }

    if (n == 0) {
        return memo[n][flag] = (flag == 0) ? 1 : 0;
    }
    else if (n == 1) {
        return memo[n][flag] = (flag == 1) ? 1 : 0;
    }
    else {
        return memo[n][flag] = fibonacci(n - 1, flag) + fibonacci(n - 2, flag);
    }
}

int main() {
    for (int i = 0; i < 41; i++) {
        memo[i][0] = memo[i][1] = -1;
    }

    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        printf("%d %d\n", fibonacci(N, 0), fibonacci(N, 1));
    }

    return 0;
}
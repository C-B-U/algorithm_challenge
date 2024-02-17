#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int min(int a, int b) {
    return a < b ? a : b;
}

int min_cost(int a, int b, int c) {
    return min(min(a, b), c);
}

int main() {
    int n;
    scanf("%d", &n);

    int costs[n][3];

    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &costs[i][0], &costs[i][1], &costs[i][2]);
    }

    int dp[n][3];

    for (int i = 0; i < 3; ++i) {
        dp[0][i] = costs[0][i];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + costs[i][2];
    }

    int result = min_cost(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
    printf("%d\n", result);

    return 0;
}
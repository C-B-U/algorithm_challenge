#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define min(a, b) ((a) < (b) ? (a) : (b))

int main() {
    
    int n, k;
    scanf("%d %d", &n, &k);
    int dp[n + 1];
    
    for (int i = 0; i <= n; i++) {
        dp[i] = INT_MAX;
    }
    
    dp[0] = 0;
    
    for (int i = 0; i < n; i++) {
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        int m = i + i / 2;
        if (m <= n) {
            dp[m] = min(dp[m], dp[i] + 1);
        }
    }
    printf("%s\n", (dp[n] <= k) ? "minigimbob" : "water");

    return 0;
}
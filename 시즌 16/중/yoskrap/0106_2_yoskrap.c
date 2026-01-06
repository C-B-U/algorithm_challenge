#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    double dp[n];
    scanf("%lf", &dp[0]);
    double max = dp[0];
    
    for(i=1;i<n;i++){
        scanf("%lf", &dp[i]);
        if (dp[i-1]*dp[i] > dp[i]) dp[i] *= dp[i-1];
        if (dp[i] > max) max = dp[i];
    }
    
    printf("%.3lf", max);
    
    return 0;
}
#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);
    
    int dp[n + 1];
    dp[1] = 0;
    
    for(i=2;i<=n;i++){
        dp[i] = dp[i-1]+1;
        if(i%2 == 0 && dp[i/2]+1 < dp[i]) dp[i] = dp[i/2]+1;
        if(i%3 == 0 && dp[i/3]+1 < dp[i]) dp[i] = dp[i/3]+1;
    }
    
    printf("%d", dp[n]);
    
    return 0;
}
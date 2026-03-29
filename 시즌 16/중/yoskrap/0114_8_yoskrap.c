#include <stdio.h>

int main() {
    int n, i, j;
    scanf("%d", &n);
    int dp[1516][15] = {0};
    dp[0][0] = 1;
    for(i=1;i<=n;i++){
        for(j=0;j<15;j++){
            dp[i][(j*10+1)%15] = (dp[i][(j*10+1)%15] + dp[i-1][j])%1000000007;
            dp[i][(j*10+5)%15] = (dp[i][(j*10+5)%15] + dp[i-1][j])%1000000007;
        }
    }
    
    printf("%d", dp[n][0]);
    
    return 0;
}
#include <stdio.h>

int main() {
    int n;
    int i, j;
    scanf("%d", &n);
    
    int dp[n+1];
    dp[0] = 0;
    
    for(i=1;i<=n;i++){
        dp[i] = dp[i-1] + 1;
        
        for(j=1;j*j<=i;j++){
            if (dp[i-j*j] + 1 < dp[i]){
                dp[i] = dp[i-j*j] + 1;
            }
        }
    }
    
    printf("%d", dp[n]);
    
    return 0;
}
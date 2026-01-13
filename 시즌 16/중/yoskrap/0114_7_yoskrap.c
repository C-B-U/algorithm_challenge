#include <stdio.h>

int main() {
    int t, i, j, k;
    scanf("%d", &t);
    
    int graph[10][4] = { {7}, {2, 4}, {1, 3, 5}, {2, 6},
                      {1, 5, 7}, {2, 4, 6, 8}, {3, 5, 9},
                      {4, 8, 0}, {5, 7, 9}, {6, 8} };
    int rear[10] = {1, 2, 3, 2, 3, 4, 3, 3, 3, 2};
    int dp[1001][10] = {0};
    for(i=0;i<10;i++) dp[1][i] = 1;
    for(i=2;i<1001;i++){
        for(j=0;j<10;j++){
            for(k=0;k<rear[j];k++){
                dp[i][j] += dp[i-1][graph[j][k]];
                dp[i][j] %= 1234567;
            }
        }
    }
    
    for(i=0;i<t;i++){
        int c, res = 0;
        scanf("%d", &c);
        
        for(j=0;j<10;j++){
            res += dp[c][j];
            res %= 1234567;
        }
        printf("%d\n", res);
    }
    
    return 0;
}
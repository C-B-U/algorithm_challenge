#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dice[10001][7];
int front[7];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, num;
    int ans = 0, sum = 0, maxN = 0, idx, std;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 6; j++) {
            scanf("%d", &dice[i][j]);
        }
    }
    front[1] = 6;
    front[2] = 4;
    front[3] = 5;
    front[4] = 2;
    front[5] = 3;
    front[6] = 1;

    for(int i = 1; i <= 6; i++) {
        sum = 0;
        maxN = 0;

        for(int p = 1; p <= 6; p++) {
            if(p != dice[1][i] && p != dice[1][front[i]]) {
                maxN = max(maxN, p);
            }
        }
        sum += maxN;
        std = dice[1][i];
        for(int j = 2; j <= n; j++) {
            maxN = 0;
            for(int x = 1; x <= 6; x++) {
                if(dice[j][x] == std) {
                    idx = x;
                    break;
                }
            }
            int top = dice[j][front[idx]];
            int bottom = std;
            for(int k = 1; k <= 6; k++) {
                if(k != top && k != bottom) {
                    maxN = max(maxN, k);
                }
            }
            sum += maxN;
            std = top;
        }
        ans = max(ans, sum);
        sum = 0;
    }
    printf("%d", ans);
    return 0;
}
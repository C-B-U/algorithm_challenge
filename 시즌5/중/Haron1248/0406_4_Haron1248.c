#include <stdio.h>
#include <stdlib.h>

int get_min(int, int);

int main() {
	int n, min_way, i;
	scanf("%d", &n);
	int** cost = (int**)malloc(sizeof(int*) * n);
	int** dp = (int**)malloc(sizeof(int*) * n);

	for (i = 0; i < n; i++) {
		cost[i] = (int*)calloc(3, sizeof(int));
		dp[i] = (int*)calloc(3, sizeof(int));

		for (int j = 0; j < 3; j++) {
			scanf("%d", &cost[i][j]);
			if (i == 0) dp[0][j] = cost[0][j];
			else dp[i][j] = get_min(dp[i - 1][(j == 0) ? 1 : 0], dp[i - 1][(j == 2) ? 1 : 2]) + cost[i][j];
		}
	}
	min_way = get_min(dp[n - 1][0], get_min(dp[n - 1][1], dp[n - 1][2]));
	printf("%d\n", min_way);

	return 0;
}

int get_min(int a, int b) {
	if (a < b) return a;
	else return b;
}

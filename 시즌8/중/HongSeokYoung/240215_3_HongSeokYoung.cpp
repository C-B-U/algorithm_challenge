#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int dp[1000001];

int SelectNumber(int N) {
	dp[1] = 0;

	for (int i = 2; i <= N; i++) {
		
		dp[i] = dp[i - 1] + 1;

		if (i % 2 == 0) {
			if (dp[i] > dp[i / 2] + 1) {
				dp[i] = dp[i / 2] + 1;
			}
		}

		if (i % 3 == 0) {
			if (dp[i] > dp[i / 3] + 1) {
				dp[i] = dp[i / 3] + 1;
			}
		}
	}
	return dp[N];
}

int main(void) {
	int N;
	scanf("%d", &N);

	int answer = SelectNumber(N);
	printf("%d", answer);
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, N, a_win = 0, b_win = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);

		if (a > b) a_win += 1;
		else if (a < b) b_win += 1;
	}

	printf("%d %d", a_win, b_win);

	return 0;
}
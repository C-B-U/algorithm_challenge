#include<stdio.h>

int main() {
	int N, side = 2, pentagon = 5;
	scanf("%d", &N);

	for (int i = 1; i < N; i++) {
		side++;
		pentagon = (pentagon + (side * 3 - 2)) % 45678;
	}

	printf("%d\n", pentagon);
}

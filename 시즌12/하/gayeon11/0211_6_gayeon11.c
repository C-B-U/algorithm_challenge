#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
	int N, M, i, price = 0, number = 0, sum = 0;
	int A[11];
	int B[11];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &price);
		A[i] = price;
		price = 0;
	}
	
	scanf("%d", &M);

	for (i = 0; i < M; i++) {
		scanf("%d", &number);
		B[i] = number;
		number = 0;
	}

	for (i = 0; i < M; i++) {
		sum += A[B[i] - 1];
	}

	printf("%d", sum);
	return 0;
}
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	
	int N = 0;
	int A[10] = { 0, };

	scanf("%d", &N);

	for (int i = 0; i < N;++i) {
		scanf("%d", &A[i]);
	}

	int M = 0;
	int B[10] = { 0, };

	scanf("%d", &M);

	for (int i = 0; i < M;++i) {
		scanf("%d", &B[i]);
	}
	
	int total = 0;
	
	for (int i = 0; i < M;++i) {
		total += A[B[i] - 1];
	}

	printf("%d", total);
	return 0;
}


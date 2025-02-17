#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
	int N, i, j, count = 0, number = 0; 
	// count: 소수 개수 세기, number: 나눠진 횟수 세기
	int li[101] = { 0 };

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &li[i]);
	}

	for (i = 0; i < N; i++) {
		for (j = 1; j < li[i] + 1; j++) {
			if (li[i] % j == 0) number += 1;
		}
		
		if (number == 2) {
			count += 1;
		}
		number = 0;
	}

	printf("%d", count);

	return 0;
}
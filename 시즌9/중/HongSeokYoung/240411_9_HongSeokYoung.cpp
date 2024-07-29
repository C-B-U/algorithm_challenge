#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N;
	int sum = 1;
	int total = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N - 2; i++) {
		
		total += sum;
		
		if (i % 2 == 0) {
			sum += 1;
		}

	}
	printf("%d", total);
    
    return 0;
}
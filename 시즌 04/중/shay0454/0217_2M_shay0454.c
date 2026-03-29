#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int factorial(int);
int main() {
	int n, a;
	scanf("%d", &n);
	int* sum = (int*)calloc(n, sizeof(int));
	//어지럽다...
	for (int z = 0; z < n; z++) {
		scanf("%d", &a);
		int x3 = a / 3, x2 = a / 2, x1;
		for (int i = 0; i <= x3; i++) {
			for (int j = 0; j <= x2; j++) {
				x1 = a - i * 3 - j * 2;
				if (i * 3 + j * 2 + x1 > a || x1 < 0) break;
				sum[z] += (factorial(i + j + x1) / (factorial(i) * factorial(j) * factorial(x1)));
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", sum[i]);
	}
	return 0;
}

int factorial(int x) {
	int a = 1;
	for (int i = 1; i <= x; i++) {
		a *= i;
	}
	return a;
}

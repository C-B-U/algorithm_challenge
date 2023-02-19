#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int a, b, n,answer;
	scanf("%d %d %d", &a, &b, &n);
	for (int i = 0; i <= n; i++) {
		answer = a / b;
		a = 10*(a % b);
	}
	printf("%d", answer);
	return 0;
}

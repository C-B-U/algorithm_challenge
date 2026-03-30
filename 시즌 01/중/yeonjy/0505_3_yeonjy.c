#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int n, max;
	scanf("%d", &n);
	int* ary = (int*)malloc(sizeof(int) * n);
	int* tmp = (int*)malloc(sizeof(int) * n);

	

	for (int i = 0; i < n; i++) {
		scanf("%d", &ary[i]);
	}
	*(tmp) = *(ary);
	max = *(ary);
	for (int i = 1; i < n; i++) {
		*(tmp + i) = *(tmp + i - 1) + *(ary + i) > *(ary + i) ? *(tmp + i - 1) + *(ary + i) : *(ary + i);
	}
	for (int i = 0; i < n; i++) {
		max = *(tmp + i) > max ? *(tmp + i) : max;
	}
	printf("%d", max);

	free(ary);
	free(tmp);

	return 0;
}

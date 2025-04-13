#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int all, sum = 0;
	int book[10];

	scanf("%d", &all);

	for (int i = 0; i < 9; i++) {
		scanf("%d", &book[i]);
		sum += book[i];
	}

	printf("%d", all - sum);

	return 0;
}
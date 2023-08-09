#include <stdio.h>
#include <stdlib.h>

int many = 0;
int fingers[1000000];
int sums[1000000];
int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;
	if (num1 > num2) {
		return -1;
	}
	else if (num1 < num2) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	scanf("%d", &many);
	for (int i = 0; i < many; i++) {
		scanf("%d", &fingers[i]);
	}
	qsort(fingers, many, sizeof(int), compare);
	int count = 0, flag = 0;
	for (int i = 0; i < many - 2; i++) {
		if (fingers[i] < fingers[i + 1] + fingers[i + 2]) {
			printf("%d", fingers[i] + fingers[i + 1] + fingers[i + 2]);
			return 0;
		}
	}
	if (count == 0) {
		printf("%d", -1);
	}
	return 0;
}
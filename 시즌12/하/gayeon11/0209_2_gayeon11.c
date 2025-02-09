#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char kmp[101];
	scanf("%100s", kmp);

	printf("%c", kmp[0]);

	for (int i = 1; kmp[i] != '\0'; i++) {
		if (kmp[i] == '-') {
			printf("%c", kmp[i + 1]);
		}
	}
	return 0;
}
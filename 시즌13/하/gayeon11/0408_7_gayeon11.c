#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
	int T, l = 0;
	char li[1000];

	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%s\n", li);
		l = strlen(li);

		printf("%c%c\n", li[0], li[l - 1]);
	}
	return 0;
}
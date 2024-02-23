#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int samecompare(char arrX[], char arrY[]) {
	int i;
	int count = 0;

	for (i = 0; i < strlen(arrX); i++) {
		if (arrX[i] == arrY[i]) {
			count += 1;
		}
	}
	return strlen(arrX)-count;
}

int differentcompare(char arrX[], char arrY[]) {
	int i,a;
	int maxcount = 0;

	for (i = 0; i < strlen(arrY) - strlen(arrX) + 1; i++) {
		int count = 0;
		for (a = 0; a < strlen(arrX); a++) {
			if (arrX[a] == arrY[a+i]) {
				count += 1;
			}
		}
		if (maxcount < count) {
			maxcount = count;
		}
	}

	return strlen(arrX)-maxcount;
}

int main(void) {
	char X[50];
	char Y[50];

	scanf("%s %s", X, Y);

	if (strlen(X) == strlen(Y)) {
		int samecount = samecompare(X, Y);
		printf("%d\n", samecount);
	}
	else {
		int differcount = differentcompare(X, Y);
		printf("%d\n", differcount);
	}
	return 0;
}
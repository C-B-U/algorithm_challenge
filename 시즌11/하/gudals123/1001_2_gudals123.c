#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {
	
	char map[100][100];

	int N = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '\n')
				--j;
		}
	}

	int widthCount = 0;
	int lenghtCount = 0;

	
	for (int i = 0; i < N; ++i) {
		int temp = 0;
		for (int j = 0; j < N; ++j) {
			if (map[i][j] == '.')
				++temp;
			else if (map[i][j] == 'X')
				temp = 0;
			if (temp == 2)
				++widthCount;
		}
	}

	for (int i = 0; i < N; ++i) {
		int temp = 0;
		for (int j = 0; j < N; ++j) {
			if (map[j][i] == '.')
				++temp;
			else if (map[j][i] == 'X')
				temp = 0;
			if (temp == 2)
				++lenghtCount;
		}
	}

	printf("%d %d", widthCount, lenghtCount);
	return 0;
}
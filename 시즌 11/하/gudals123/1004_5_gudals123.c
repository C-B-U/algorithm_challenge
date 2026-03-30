#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

void Sort(int arr[]) {
	int temp = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			if (arr[i] < arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void) {

	int T = 0;
	int score[10][5];

	scanf("%d", &T);

	for (int i = 0; i < T; ++i) {
		scanf("%d %d %d %d %d", &score[i][0], &score[i][1], &score[i][2], &score[i][3], &score[i][4]);
		Sort(score[i]);
	}

	for (int i = 0; i < T; ++i) {
		if (score[i][1] - score[i][3] >= 4)
			printf("KIN\n");
		else
			printf("%d\n", score[i][1] + score[i][2] + score[i][3]);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void bubbleSort(int arr[], int n) {
	int i, j, temp;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n, distance;
	int list[10000] = { 0 };

	while(1)
	{
		int check = 0;
		scanf("%d", &n);

		if (n == 0) {
			break;
		}
		
		else {
			for (int i = 0; i < n; i++) {
				scanf("%d", &distance);
				list[i] = distance;
			}
		}

		bubbleSort(list, n);

		for (int j = 1; j < n; j++) {
			if (list[j-1] - list[j] > 200) {
				check += 1;
				break;
			}
		}

		if (list[0] < 1322) {
			check += 1;
		}

		if (check == 0) {
			printf("POSSIBLE\n");
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}

	return 0;
}
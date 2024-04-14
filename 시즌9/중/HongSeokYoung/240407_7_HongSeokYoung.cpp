#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int num, N;

	scanf("%d", &num);

	for (int i = 0; i < num; i++) {
		int check = 2;
		int count = 0;

		scanf("%d", &N);

		while (1) {

			if (N % check == 0) {
				count += 1;
				N = N / check;

				if (N == 1) {
					printf("%d %d\n", check, count);
					break;
				}
			}

			else {
				if (count > 0) {
					printf("%d %d\n",check,count);
					count = 0;
				}
				else {
					check += 1;
				}
			}
		}
	}
	return 0;
}
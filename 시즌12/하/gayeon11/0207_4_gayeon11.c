#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int n, i;

	while (1) {
		int cnt = 0;
		int sum = 0;
		int yag[100001] = { 0 }; //약수 배열..

		scanf("%d", &n);

		if (n == -1) break;

		for (i = 1; i < n; i++) {
			if (n % i == 0) {
				yag[cnt] = i;
				cnt++;
				sum += i;
			}
		}

		if (n == sum) {
			int last_index;
			for (i = 0; i < sizeof(yag) / sizeof(int); i++) {
				if (yag[i] == 0) break;
				last_index = i;
			}

			printf("%d =", n);
			for (i = 0; i < sizeof(yag) / sizeof(int); i++) {
				if (yag[i] == 0) break;
				printf(" %d", yag[i]);
				if (i != last_index) printf(" +");
			}
			printf("\n");
		}

		if (n != sum) printf("%d is NOT perfect.\n", n);

	}

	return 0;
}
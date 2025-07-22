#include <stdio.h>

int main() {

	int t = 0;
	int max = 0;
	int n[100000];

	scanf("%d", &t);

	for (int i = 0; i < t; i++) {

		scanf("%d", &n[i]);
	}

	for (int i = 0; i < t; i++) {

		max = n[i];

		for (int j = 0; n[i] != 1; j++) {

			if (n[i] % 2 == 0) {
				n[i] /= 2;
			}
			else {
				n[i]=(n[i] * 3) + 1;
			}

			if (max < n[i]) {
				max = n[i];
			}
		}
		printf("%d\n", max);

	}

	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int fact(int x) {
	if (x == 0 || x == 1) return 1;
	return x * fact(x - 1);
}
void replace_index(int* blocked_index, int p, int last) {
	if (p != 0) {
		if (blocked_index[p - 1] == blocked_index[p] - 1) {
			replace_index(blocked_index, p - 1, last - 1);
			blocked_index[p] = last;
			return;
		}
	}
	blocked_index[p]--;
}

int main() {
	int n, i, j;
	while (scanf("%d", &n)) {
		if (n == 0) break;
		int num_case = 1;
		int* arr_index = (int*)malloc(sizeof(int) * n - 6);
		int* arr = (int*)malloc(sizeof(int) * n);
		for (i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			if (i > 5) arr_index[i - 6] = i;
		}
		num_case = fact(n);
		num_case /= 720 * fact(n - 6);
		for (i = 0; i < num_case; i++) {
			int t = 0;
			for (j = 0; j < n; j++) {
				if (arr_index[t] == j) {
					t++;
					continue;
				}
				printf("%d ", arr[j]);
			}
			printf("\n");
			replace_index(arr_index, n - 7, n - 1);
		}
		printf("\n");
	}
	return 0;
}

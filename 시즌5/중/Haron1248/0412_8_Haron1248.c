#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, i, j, pre;
	scanf("%d", &n);
	int min_move = n - 1;
	int* arr = (int*)calloc(n, sizeof(int));
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == n) break;
	}
	pre = arr[i] - 1;
	for (j = i; j > 0; j--) {
		if (arr[j - 1] == pre) {
			min_move--;
			pre--;
		}
	}
	printf("%d\n", min_move);
	return 0;
}

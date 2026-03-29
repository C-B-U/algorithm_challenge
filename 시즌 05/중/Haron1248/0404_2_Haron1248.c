#include <stdio.h>
#include <stdlib.h>
int main() {
	int n, m, max_size = 20000001, num;
	scanf("%d", &n);
	int* cards = (int*)calloc(max_size, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		cards[max_size - ((max_size + 1) / 2) + num]++;
	}

	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &num);
		printf("%d ", cards[max_size - ((max_size + 1) / 2) + num]);
	}
}

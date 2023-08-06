#include <stdio.h>
#include <stdlib.h>

void get_size(int** map, int m, int n, int x, int y, int& size);
void search(int** map, int m, int n, int k);

int main() {
	int m, n, k, i;
	scanf("%d %d %d", &m, &n, &k);
	int** map = (int**)malloc(m * sizeof(int*));
	for (i = 0; i < m; i++) {
		map[i] = (int*)calloc(n, sizeof(int));
	}

	int x1, y1, x2, y2;
	for (i = 0; i < k; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = -1;
			}
		}
	}
	search(map, m, n, k);
	return 0;
}

void get_size(int** map, int m, int n, int x, int y, int& size) {
	map[y][x] = 1;
	if (x + 1 < n && map[y][x + 1] == 0) {
		get_size(map, m, n, x + 1, y, ++size);
	}
	if (y - 1 >= 0 && map[y - 1][x] == 0) {
		get_size(map, m, n, x, y - 1, ++size);
	}
	if (x - 1 >= 0 && map[y][x - 1] == 0) {
		get_size(map, m, n, x - 1, y, ++size);
	}
	if (y + 1 < m && map[y + 1][x] == 0) {
		get_size(map, m, n, x, y + 1, ++size);
	}
}

void search(int** map, int m, int n, int k) {
	int count = 0, size;
	int* arr = (int*)malloc(sizeof(int) * m * n);
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			if (map[j][i] == 0) {
				size = 1;
				get_size(map, m, n, i, j, size);
				arr[count] = size;
				count++;
			}
		}
	}

	printf("%d\n", count);
	for (int i = 0; i < count; i++)
		printf("%d ", arr[i]);
}

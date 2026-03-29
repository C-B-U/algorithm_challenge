#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m, min_count = 32;
	scanf("%d %d", &n, &m);
	char** map = (char**)malloc(sizeof(char*) * n);
	
	for (int i = 0; i < n; i++) {
		map[i] = (char*)malloc(sizeof(char) * m);
		scanf("%s", map[i]);
	}

	for (int cur_row = 0; cur_row < n - 7; cur_row++) {
		for (int cur_col = 0; cur_col < m - 7; cur_col++) {
			int count_B = 0, count_W = 0;

			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if ((i + j) % 2 == 0) {
						if (map[cur_row + i][cur_col + j] != 'B') count_B++;
						if (map[cur_row + i][cur_col + j] != 'W') count_W++;
					}
					else {
						if (map[cur_row + i][cur_col + j] != 'B') count_W++;
						if (map[cur_row + i][cur_col + j] != 'W') count_B++;
					}
				}
			}

			if (count_B < count_W && count_B < min_count) min_count = count_B;
			else if (count_W < count_B && count_W < min_count) min_count = count_W;
		}
	}

	printf("%d\n", min_count);
}

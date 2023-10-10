#include <stdio.h>
#include <stdlib.h>

typedef struct arr2D {
	int** map;
	int lx, ly;
} Map;

typedef struct queue {
	int* arr;
	int start;
	int len;
} Queue;

void searchWarm_BFS(Map map, Queue que) {
	if (que.len == 0)
		return;

	int fx = que.arr[que.start] % map.lx;
	int fy = que.arr[que.start] / map.lx;

	// 위쪽 탐색
	if ((fy) - 1 >= 0 && map.map[(fy) - 1][fx] == 1) {
		map.map[(fy) - 1][fx] = 0;
		que.arr[que.start + que.len] = que.arr[que.start] - map.lx;
		que.len++;
	}

	// 오른쪽 탐색
	if ((fx) + 1 < map.lx && map.map[fy][(fx) + 1] == 1) {
		map.map[fy][(fx) + 1] = 0;
		que.arr[que.start + que.len] = que.arr[que.start] + 1;
		que.len++;
	}

	// 아래쪽 탐색
	if ((fy) + 1 < map.ly && map.map[(fy) + 1][fx] == 1) {
		map.map[(fy) + 1][fx] = 0;
		que.arr[que.start + que.len] = que.arr[que.start] + map.lx;
		que.len++;
	}

	// 왼쪽 탐색
	if ((fx) - 1 >= 0 && map.map[fy][(fx) - 1] == 1) {
		map.map[fy][(fx) - 1] = 0;
		que.arr[que.start + que.len] = que.arr[que.start] - 1;
		que.len++;
	}

	que.start++;
	que.len--;
	return searchWarm_BFS(map, que);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		int m, n, k;
		scanf("%d %d %d", &m, &n, &k);
		
		Map map;
		map.map = (int**)malloc(sizeof(int*) * n);
		for (int i = 0; i < n; i++)
			map.map[i] = (int*)calloc(m, sizeof(int));
		map.lx = m;
		map.ly = n;

		int x, y;
		for (int i = 0; i < k; i++) {
			scanf("%d %d", &x, &y);
			map.map[y][x] = 1;
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map.map[i][j] == 1) {
					Queue que;
					que.arr = (int*)malloc(sizeof(int) * k);
					que.start = 0, que.len = 0;

					map.map[i][j] = 0;
					que.arr[que.start] = i * map.lx + j;
					que.len++;

					searchWarm_BFS(map, que);
					result++;
				}
			}
		}

		printf("%d\n", result);
	}
}

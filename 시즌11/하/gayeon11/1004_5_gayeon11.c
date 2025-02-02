#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
	int T; //1 <= T <= 10
	int a, b, c, d, e, max = 0, min = 0, sum = 0;
	char print[11][10];
	int arr[6];

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
		arr[0] = a, arr[1] = b, arr[2] = c, arr[3] = d, arr[4] = e;
		max = arr[0], min = arr[0];
		
		// 최고점, 최저점 찾기
		for (int j = 1; j < 5; j++) {
			if (max < arr[j]) max = arr[j];
			if (min > arr[j]) min = arr[j];
		}

		int temp[3], idx = 0, max_removed = 0, min_removed = 0;
		for (int j = 0; j < 5; j++) {
			if (arr[j] == max && max_removed == 0) {
				max_removed = 1;  // 최대값 한 번만 제외
				continue;
			}
			if (arr[j] == min && min_removed == 0) {
				min_removed = 1;  // 최소값 한 번만 제외
				continue;
			}
			temp[idx++] = arr[j];
			if (idx == 3) break; // 나머지 3명만 필요하므로
		}

		// 나머지 3명의 점수 중 최고점 최저점 계산
		int temp_max = temp[0], temp_min = temp[0];
		for (int j = 1; j < 3; j++) {
			if (temp_max < temp[j]) temp_max = temp[j];
			if (temp_min > temp[j]) temp_min = temp[j];
		}
		
		if ((temp_max - temp_min) >= 4) {
			sprintf(print[i], "KIN");
		}
		else {
			sprintf(print[i], "%d", temp[0] + temp[1] + temp[2]);
		}
	}

	for (int i = 0; i < T; i++) {
		printf("%s\n", print[i]);
	}
	return 0;
}

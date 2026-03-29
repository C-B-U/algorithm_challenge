#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, l, count = 0; // 사용한 테이프 개수
	scanf("%d %d", &n, &l);
	int* pipe = (int*)calloc(1000, sizeof(int)); // 파이프 초기화
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		pipe[tmp - 1] = 1;
	}
	
	int cor_index = 0, remaining_l = 0; // 현재 조회 중인 인덱스, 남은 테이프 길이
	while (cor_index < 1000) {
		if (pipe[cor_index++] != 0 || remaining_l != 0) { // 파이프가 파손되었거나 테이프 길이가 남을 때
			if (remaining_l > 0) remaining_l--; // 남은 테이프 사용
			else { // 테이프 전부 사용했으니, 새 테이프 꺼내서 사용
				count++;
				remaining_l = l - 1;
			}
		}
	}

	printf("%d\n", count);
}

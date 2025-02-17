#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i;

	scanf("%d", &N);

	int* li = (int*)malloc(N * sizeof(int));
	if (li == NULL) {
		printf("메모리 할당 실패\n");
		return 1;
	}

	scanf("%d", &li[0]);
	int min = li[0], max = li[0];

	for (i = 1; i < N; i++) {
		scanf("%d", &li[i]);

		if (min > li[i]) min = li[i];
		if (max < li[i]) max = li[i];
	}

	printf("%d %d", min, max);

	free(li);
	return 0;
}

/* 
원래 코드를 이렇게 작성 했었는데
#include <stdio.h>

int main() {
	int N, i;
	int li[1000000] = { 0 }; 런타임 에러 segfault가 발생함.
	-> malloc 함수 사용.

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &li[i]);
	}
	max = li[0];
	min = li[0];

	for (i = 1; i < N; i++) {
		if (min > li[i]) min = li[i];
		if (max < li[i]) max = li[i];
	}

	printf("%d %d", min, max);
	return 0;
}
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, K, count = 0;
	int div[37] = { 0 }; 
	// 10,000의 약수 개수가 25라길래 배열 사이즈를 26으로 했었으나,
	// 왠지 모르게 런타임 에러 발생.. 배열 크기 36까진 에러나고
	// 37부터는 정상!

	scanf("%d %d", &N, &K);

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			div[count] = i;
			count++;
		}
	}

	if (count < K) printf("0");
	else printf("%d", div[K - 1]);

	return 0;
}
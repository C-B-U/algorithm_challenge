#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N, K, count = 0;
	int div[37] = { 0 }; 
	// 10,000�� ��� ������ 25��淡 �迭 ����� 26���� �߾�����,
	// ���� �𸣰� ��Ÿ�� ���� �߻�.. �迭 ũ�� 36���� ��������
	// 37���ʹ� ����!

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
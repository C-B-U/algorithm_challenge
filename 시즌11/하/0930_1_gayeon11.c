#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
int main() {
	int N = 0, price = 0, M = 0, number = 0; // 1<= N <= 10
	int A[11]; // �ڳ� �޴��� ����
	int B[11]; // �ڳ� ��ȣ
	int all = 0; // �հ�

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &price); // ���� �ް�
		A[i] = price; // �迭�� ���ʴ�� �ְ�
		price = 0; // �� �ʱ�ȭ
	}

	scanf("%d", &M); // 1<= M <= 10

	for (int j = 0; j < M; j++) {
		scanf("%d", &number);
		B[j] = number;
		number = 0;
	}
	for (int k = 0; k < M; k++) {
		all = all + A[B[k]-1];
	}
	printf("%d", all);
	return 0;
}
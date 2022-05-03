/* BAEKJOON 11576*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	// A����, B����, A�������� ��Ÿ�� ������ �ڸ��� ����, A���� ���� 10�������� �ٲ� �� ���� ����
	int Anotation, Bnotation, m, tmp = 0;
	scanf("%d %d", &Anotation, &Bnotation);	// A, B���� �Է�
	scanf("%d", &m);	// A�������� ��Ÿ�� ������ �ڸ��� ���� �Է�
	int* Aarray = (int*)malloc(sizeof(int) * m);

	for (int i = m-1; i >= 0; --i) {	// A������ �̷�� �ִ� ���� �Է�
		scanf("%d", Aarray + i);
	}
	
	/* A������ 10������ �ٲٱ� */
	for (int i = 0; i < m; i++) {
		tmp += *(Aarray + i) * pow(Anotation, i);
	}

	/* 10������ �ٲ� ���� B���� ������ ��ȯ */
	int ary[100] = { 0 };
	int i = 0, num = 0, quo = 0;
	do {
		ary[i++] = tmp % Bnotation;
		tmp /= Bnotation;
	} while (tmp != 0);

	for (int j = i-1; j >= 0; --j) {
		printf("%d ", ary[j]);
	}
	free(Aarray);
	return 0;
}

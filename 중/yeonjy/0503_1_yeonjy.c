/* BAEKJOON 11576*/
<<<<<<< HEAD
/*
�Է�1: A�̷����� B��������   (2 �̻� 30 ����)
�Է�2: A�������� ��Ÿ�� ������ �ڸ����� ���� (1 <=  <= 25)
�Է�3: A������ �̷�� �ִ� ���� m���� ������ �������� ���� �ڸ������� ���ʴ�� �־���
*** �� ���ڴ� 0�̻� A�̸�
*** 0���� �����ϴ� ���� �������� ����
*** A�������� ��Ÿ�� ���� 10�������� ��ȯ���� ���� ���� ���� �����̸� 2^20 ���� �۴�.
*/
/*
* Ǯ��
* A������ 10������ �ٲٱ�
* B�� ������ ������ �迭�� ���� (���� 0�� �ɶ�����)
*/
=======
>>>>>>> de8b6cbadb35400fcd26540cb706ec2d4f4b68f6

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

<<<<<<< HEAD


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
=======
int main() {
	int Anotation, Bnotation, m, tmp = 0;
	scanf("%d %d", &Anotation, &Bnotation);
	scanf("%d", &m);
	int* Aarray = (int*)malloc(sizeof(int) * m);

	for (int i = m-1; i >= 0; --i) {
		scanf("%d", Aarray + i);
	}
	
>>>>>>> de8b6cbadb35400fcd26540cb706ec2d4f4b68f6
	for (int i = 0; i < m; i++) {
		tmp += *(Aarray + i) * pow(Anotation, i);
	}

<<<<<<< HEAD
	/* 10������ �ٲ� ���� B���� ������ ��ȯ */
=======
>>>>>>> de8b6cbadb35400fcd26540cb706ec2d4f4b68f6
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

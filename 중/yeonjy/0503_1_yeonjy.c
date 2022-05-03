#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main() {
	// A진법, B진법, A진법으로 나타낸 숫자의 자리수 개수, A진법 수를 10진법으로 바꾼 수 저장 변수
	int Anotation, Bnotation, m, tmp = 0;
	scanf("%d %d", &Anotation, &Bnotation);	// A, B진법 입력
	scanf("%d", &m);	// A진법으로 나타낸 숫자의 자리수 개수 입력
	int* Aarray = (int*)malloc(sizeof(int) * m);

	for (int i = m-1; i >= 0; --i) {	// A진법을 이루고 있는 숫자 입력
		scanf("%d", Aarray + i);
	}
	
	/* A진법을 10진수로 바꾸기 */
	for (int i = 0; i < m; i++) {
		tmp += *(Aarray + i) * pow(Anotation, i);
	}

	/* 10진수로 바꾼 수를 B진수 값으로 변환 */
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

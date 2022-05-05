/* BAEKJOON 11576*/
/*
입력1: A미래진법 B정이진법   (2 이상 30 이하)
입력2: A진법으로 나타낸 숫자의 자리수의 개수 (1 <=  <= 25)
입력3: A진법을 이루고 있는 숫자 m개가 공백을 구분으로 높은 자릿수부터 차례대로 주어짐
*** 각 숫자는 0이상 A미만
*** 0으로 시작하는 경우는 존재하지 않음
*** A진법으로 나타낸 수를 10진법으로 변환했을 때의 값은 양의 정수이며 2^20 보다 작다.
*/
/*
* 풀이
* A진법을 10진수로 바꾸기
* B로 나눠서 나머지 배열에 저장 (몫이 0이 될때까지)
*/

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

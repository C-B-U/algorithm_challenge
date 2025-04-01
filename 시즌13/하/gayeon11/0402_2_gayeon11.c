#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double factorial(int num);
double calculate_e(int n); // 함수 선언 필요없는 코드이지만 습관적으로 적는 연습하기.!!!

double factorial(int num) { // 팩토리얼 구하는 함수 
	double result = 1;

	for (int i = 1; i <= num; i++) {
		result *= i;
	}
	return result;
}

double calculate_e(int n) { // e 계산하는 함수
	double e = 0;

	for (int i = 0; i < n; i++) {
		e += 1.0 / factorial(i);
	}
	return e;
}

int main() {
	printf("n e\n");
	printf("- -----------\n");

	for (int n = 0; n <= 9; n++) {
		if (n == 0 || n == 1) {
			printf("%d %.f\n", n, calculate_e(n+1));
		}
		else if (n == 2) {
			printf("%d %.1f\n", n, calculate_e(n+1));
		}
		else {
			printf("%d %.9f\n", n, calculate_e(n+1));
		}
	}

	return 0;
}
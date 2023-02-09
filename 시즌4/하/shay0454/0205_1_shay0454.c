#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main() {
	int l=0,a=0, num = 0;
	scanf("%d", &a);
	num = a;
	num = 10 * (num % 10) + ((num / 10 + num % 10) % 10);
	l++;
	while (a != num) {
		num = 10*(num%10)+((num / 10 + num % 10)%10);
		l++;
	}
	printf("%d", l);
	return 0;
}

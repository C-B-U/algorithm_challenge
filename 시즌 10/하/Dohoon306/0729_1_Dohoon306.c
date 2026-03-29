#include<stdio.h>
int main() {
	int num, n, circle = 1, first, second;
	scanf("%d", &num);
	n = num;
	do{
		first = num / 10;
		second = num % 10;
		num = second * 10 + (first + second) % 10;
		circle++;
	} while (num != n);
	printf("%d\n", circle - 1);
}

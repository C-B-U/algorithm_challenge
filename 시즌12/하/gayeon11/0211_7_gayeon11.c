#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
    int a, b;

    scanf("%d", &a);
    scanf("%d", &b);

    printf("%d\n", a * (b % 10));

    printf("%d\n", a * ((b/10)%10));

    printf("%d\n", a * ((b/100)%10));

    printf("%d", a * b);
	return 0;
}
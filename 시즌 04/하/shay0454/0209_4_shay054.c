#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int x,y,tx, ty,a,b;
	scanf("%d %d %d %d", &x, &y, &tx, &ty);
	if (tx - x > ty - y) a = ty - y;
	else a = tx - x;
	if (x > y) b = y;
	else b = x;
	if (a > b) printf("%d", b);
	else printf("%d", a);
	return 0;
}

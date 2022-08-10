#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

int cal(int num);

int main() {
	int num;
	scanf("%d", &num);
	printf("%d", cal(num));

	return 0;
}

int cal(int num)
{
	int n = num - 2;
	int res = 0;
	if (num == 1)
		return 1;
	for (int i = 0; i < MAX; ++i) {
		if (n / 6 >= i) {
			n -= 6 * i;
		}
		else
			return i + 1;
	}

	return res;
}

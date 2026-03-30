#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
	long long int n, m, a;
	scanf("%lld %lld", &n, &m);
	if (n >= m)
		printf("0");
	else {
		long long int result = 1;
		for (long long int i = 1; i <= n; i++) {
			result = (result * i) % m;
		}

		printf("%lld", result);
	}
}


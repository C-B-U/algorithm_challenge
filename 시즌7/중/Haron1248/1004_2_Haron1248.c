#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	int* not_prime = (int*)calloc(n + 1, sizeof(int));

	not_prime[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (!not_prime[i]) {
			for (int j = i * i; j <= n; j += i) not_prime[j] = 1;
		}
	}

	for (int i = m; i <= n; i++) if (not_prime[i] == 0) printf("%d\n", i);
}

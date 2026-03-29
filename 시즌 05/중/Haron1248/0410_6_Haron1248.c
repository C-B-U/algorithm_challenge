#include <stdio.h>

int get_max(int, int);
int get_min(int, int);

int main() {
	int n, m, t, tmp, count = 0, cola = 0;
	scanf("%d %d %d", &n, &m, &t);
	tmp = t;
	while (1) {
		if (get_min(n, m) > tmp) {
			cola = tmp;
			break;
		}
		if (t < 0) {
			count = 0;
			cola++;
			tmp--;
			t = tmp;
		}
		if (t % get_min(n, m) == 0) {
			count += (t + cola) / get_min(n, m);
			break;
		}
		else {
			t -= get_max(n, m);
			count++;
		}
	}
	printf("%d %d\n", count, cola);
}

int get_max(int a, int b) {
	if (a > b) return a;
	return b;
}
int get_min(int a, int b) {
	if (a < b) return a;
	return b;
}

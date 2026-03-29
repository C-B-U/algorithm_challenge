#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y, w, s;
	int count_w = 0, count_s = 0;
	long long total = 0;

	scanf("%d %d %d %d", &x, &y, &w, &s);

	if (2 * w > s) {
		if (x >= y) {
			count_s = y;
			count_w = x - y;
		}
		else {
			count_s = x;
			count_w = y - x;
		}
	}
	else {
		count_w = x + y;
	}

	if (w > s) {
		if (count_w % 2 == 0) {
			count_s += count_w;
			count_w = 0;
		}
		else {
			count_s += count_w - 1;
			count_w = 1;
		}
	}

	total = (long long)count_s * s + (long long)count_w * w;

	printf("%lld\n", total);
}

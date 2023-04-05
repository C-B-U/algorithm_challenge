#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int get_mid(int*, int, int, int);
int get_most(int*, int, int);
int n_range = 8001;

int main() {
	int n, max = -4000, min = 4000, num;
	double avg = 0;
	int* arr = (int*)calloc(n_range, sizeof(int));
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		arr[n_range - ((n_range + 1) / 2) + num]++;
		avg += num;
		if (num > max) max = num;
		if (num < min) min = num;
	}
	avg /= n;
	printf("%d\n%d\n%d\n%d\n", (int)round(avg), get_mid(arr, n, min, max), get_most(arr, min, max), max - min);
	return 0;
} 

int get_mid(int* arr, int n, int min, int max) {
	int count = 0;
	for (int i = min; i <= max; i++) {
		count += arr[n_range - ((n_range + 1) / 2) + i];
		if (count > n / 2) return i;
	}
	return 0;
}

int get_most(int* arr, int min, int max) {
	int most, maxCount = 0, f, t = 0;
	for (int i = min; i <= max; i++) {
		f = arr[n_range - ((n_range + 1) / 2) + i];
		if (f > maxCount) {
			most = i;
			maxCount = f;
			t = 0;
		}
		else if (f == maxCount) {
			if (t == 0) most = i;
			t++;
		}
	}
	return most;
}

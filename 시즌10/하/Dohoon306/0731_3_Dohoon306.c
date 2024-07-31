#include<stdio.h>
#include<stdlib.h>

int main() {
	int num, person, * arr, * n, save;
	scanf("%d", &person);
	arr = (int*)malloc(person * sizeof(int));
	n = (int*)malloc(person * sizeof(int));
	for (int i = 0; i < person; i++) {
		scanf("%d", &n[i]);
	}
	for (int i = 0; i < person; i++) {
		arr[i] = i + 1;
	}
	for (int i = 0; i < person; i++) {
		save = arr[i];
		for (int j = i; j > i - n[i]; j--) {
			arr[j] = arr[j - 1];
		}
		arr[i - n[i]] = save;
	}
	for (int i = 0; i < person; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	free(n);
}

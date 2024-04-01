#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int *numbers = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        numbers[i] = b - a;
    }

    qsort(numbers, n, sizeof(int), compare);

    int answer = 0;
    if (n % 2 == 0) {
        int start = n / 2 - 1;
        answer = numbers[start + 1] - numbers[start] + 1;
    } else {
        answer = 1;
    }

    printf("%d\n", answer);

    free(numbers);

    return 0;
}
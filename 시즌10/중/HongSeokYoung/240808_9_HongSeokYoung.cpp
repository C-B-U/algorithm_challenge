#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int* v = (int*)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    qsort(v, n, sizeof(int), compare);

    long long sum = 0;
    int multiplier = 0;

    for (int i = 0; i < n; i++) {
        sum += (long long)v[i] * multiplier;
        if (multiplier < k) {
            multiplier++;
        }
    }

    printf("%lld\n", sum);

    free(v);
    return 0;
}
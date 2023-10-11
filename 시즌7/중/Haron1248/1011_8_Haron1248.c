#include <stdio.h>
#include <stdlib.h>

int get_max_height(int max_h, int n, int needs, int* woods);
int cmpfunc(const void* a, const void* b);

int main() {
    int n, m, max_h = 0;
    scanf("%d %d", &n, &m);
    int* forest = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &forest[i]);
        if (forest[i] > max_h) max_h = forest[i];
    }

    qsort(forest, n, sizeof(int), cmpfunc);
    printf("%d\n", get_max_height(max_h, n, m, forest));

    return 0;
}

int cmpfunc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int get_max_height(int max_h, int n, int needs, int* woods) {
    int left = 0;
    int right = max_h;
    int mid;
    long long sum;
    while (left <= right) {
        mid = (left + right) / 2;
        sum = 0;
        for (int i = 0; i < n; i++)
            if (woods[i] > mid)
                sum += woods[i] - mid;

        if (sum >= needs)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return right < 0 ? 0 : right;
}

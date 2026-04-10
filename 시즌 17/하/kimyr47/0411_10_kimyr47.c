#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    if (m == 2) {
        for (int i = 0; i < n - 1; i++) {
            printf("%d %d\n", i, i + 1);
        }
        return 0;
    }

    for (int i = 1; i <= m; i++) {
        printf("0 %d\n", i);
    }

    for (int i = m + 1; i < n; i++) {
        printf("%d %d\n", i - 1, i);
    }

    return 0;
}

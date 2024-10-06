#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, a, b;
    scanf("%d %d %d %d", &n, &k, &a, &b);

    int d = n / a;
    int* data = (int*)malloc(d * sizeof(int));
    int count = 0;
    int check = 0;

    for (int i = 0; i < d; i++) {
        data[i] = k;
    }

    while (1) {
        for (int i = 0; i < d; i++) {
            data[i]--;
        }

        data[check] += b;
        check++;

        if (check == d) {
            check = 0;
        }
        count++;

        int min_value = data[0];
        for (int i = 1; i < d; i++) {
            if (data[i] < min_value) {
                min_value = data[i];
            }
        }

        if (min_value == 0) {
            printf("%d\n", count);
            break;
        }
    }

    free(data);
    return 0;
}

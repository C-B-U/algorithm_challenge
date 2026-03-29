#include <stdio.h>
int main(void) {
    int N, num, counts[50001];

    scanf("%d", &N);

    for (int i = 0; i < 50001; i++) {
        counts[i] = 0;
    }
        
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        counts[num] += 1;
    }

    int max_count = 0;
    for (int i = 0; i < 50001; i++) {
        if (counts[i] > max_count) {
            max_count = counts[i];
        }
    }

    printf("%d", max_count);
}
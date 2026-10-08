#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int *num = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    int return_value;

    for (return_value = N - 1; return_value > 0 && num[return_value - 1] < num[return_value]; return_value--);

    printf("%d", return_value);

    return 0;
}

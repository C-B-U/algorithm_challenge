#include <stdio.h>
int main() {
    int N, k;
    scanf("%d", &N);
    int A[N];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);

        if(A[i] < 0 || A[i] > 50) {
            printf("입력 오류\n");
            return 0;
        }
    }
    int max = -1;

    if(N >= 1 && N <= 50) {
        for(k = 0; k <= N; k++) {
            int count = 0;

            for(int i = 0; i < N; i++) {
                if(A[i] == k) count++;
            }

            if(count == k && k > max) {
                max = k;
            }
        }
    }

    else {
        printf("입력 오류\n");
        return 0;
    }

    printf("%d", max);
    return 0;
}

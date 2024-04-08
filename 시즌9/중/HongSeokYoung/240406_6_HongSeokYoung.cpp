#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
 
int main() {
    int P, N, M;
    scanf("%d", &P);
 
    int count, a, b;
    for (int i = 0; i < P; i++) {
        scanf("%d %d", &N, &M);
        count = 0;
        a = b = 1;
        while (1) {
            int tmp = (a + b) % M;
            a = b;
            b = tmp;
            count += 1;

            if (a==1 && b == 1) break;
        }
        printf("%d %d\n", N, count);
    }
    return 0;
}
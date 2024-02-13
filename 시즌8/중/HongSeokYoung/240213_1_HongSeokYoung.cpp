#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int zero_count = 0;
int one_count = 0;
int pos = 0;
int count[82] = { 0 };

int fibonacci(int n) {

    if (n == 0) {
        zero_count = zero_count + 1;
        return 0;
    }
    else if (n == 1) {
        one_count = one_count + 1;
        return 1;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {

    int i, a;
    int T, N = 0;
    scanf_s("%d", &T);

    for (i = 0; i < T; i++) {
        scanf_s("%d", &N);

        if (N >= 0 && N <= 40) {
            fibonacci(N);
            count[pos] = zero_count;
            count[pos + 1] = one_count;
            pos = pos + 2;
            zero_count = 0;
            one_count = 0;
        }
        else {
            printf("no\n");
        }

    }

    for (a = 0; a < pos; a+=2) {
        printf("%d %d\n", count[a], count[a+1]);
    }

}

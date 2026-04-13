// 알고리즘 챌린지17 5일차 문제

#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Duck\n");
    }
    else {
        printf("Goose\n");
    }

    return 0;
}
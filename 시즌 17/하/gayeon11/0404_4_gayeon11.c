// 알고리즘 챌린지17 4일차 문제

#include <stdio.h>

int main() {
    int n;
    long long m;
    long long max_safe_time = 0; 
    long long a;

    scanf("%d %lld", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a); // A_i 입력

        max_safe_time += (a - 1);
    }

    if (max_safe_time >= m) {
        printf("DIMI\n");
    }
    else {
        printf("OUT\n"); 
    }

    return 0;
}
// 알고리즘 챌린지17 2일차 문제

#include <stdio.h>

int main() {
    int n;
    int max_val = -1; 
    int current_val;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &current_val);

        if (current_val > max_val) {
            max_val = current_val;
        }
    }

    printf("%d\n", max_val);

    return 0;
}
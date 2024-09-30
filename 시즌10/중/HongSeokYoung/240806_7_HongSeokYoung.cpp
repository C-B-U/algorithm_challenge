// 백준 알고리즘 23305번 '수강 변경' 문제

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int data[1000001] = {0};

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        data[num]++;
    }

    int result = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (data[num] >= 1) {
            data[num]--;
        } else {
            result++;
        }
    }

    printf("%d\n", result);

    return 0;
}
// 백준 알고리즘 1813번 '논리학 교수' 문제

/*
#include <stdio.h>

int main() {
    int s[51] = {0};
    int n,t;
    int result = -1;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t>0 && t<n) {
            result = 0;
        }
        s[t] = s[t]+1;
    }

    for (int a = 1; a < n; a++) {
        if(s[a] == a) {
            result = a;
        }
    }

    printf("%d",result);

    return 0;
}
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int s[51] = {0};  // 충분한 크기의 배열 사용
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        if (value >= 0 && value < 51) {
            s[value]++;  // 빈도 카운트
        }
    }

    int result = -1;

    for (int i = 0; i < n+1; i++) {
        if (s[i] == i) {
            result = i;  // 최대값 업데이트
        }
    }

    printf("%d\n", result);

    return 0;
}

// 알고리즘 챌린지17 6일차 문제


#include <stdio.h>

int main() {
    int n;
    int count[51] = { 0 };
    int x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);

        if (x >= 0 && x <= 50) {
            count[x]++;
        }
    }

    // 참인 문장의 개수(t)를 최댓값인 N부터 0까지 역순으로 탐색
    for (int t = n; t >= 0; t--) {
        // 숫자 t가 적힌 문장의 개수가 정확히 t개라면 모순이 없디ㅏ
        if (count[t] == t) {
            printf("%d\n", t);
            return 0; 
        }
    }

    // 모순
    printf("-1\n");

    return 0;
}
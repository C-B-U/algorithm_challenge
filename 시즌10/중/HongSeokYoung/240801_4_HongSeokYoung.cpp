// 백준 알고리즘 '1003번 피보나치 함수' 문제
#include <stdio.h>

void fibonacci_count(int n, int* zero_count, int* one_count) {
    int dp[41][2]; // dp[i][0]은 f(i) 호출 시 0의 호출 횟수, dp[i][1]은 1의 호출 횟수

    dp[0][0] = 1; dp[0][1] = 0; // f(0)은 0이 1번 호출됨
    dp[1][0] = 0; dp[1][1] = 1; // f(1)은 1이 1번 호제제됨

    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }

    *zero_count = dp[n][0];
    *one_count = dp[n][1];
}

int main() {
    int T, n;
    int zero_count, one_count;

    scanf("%d", &T); // 테스트 케이스 개수 입력

    for (int i = 0; i < T; i++) {
        scanf("%d", &n); // 피보나치 수 입력
        fibonacci_count(n, &zero_count, &one_count);
        printf("%d %d\n", zero_count, one_count); // 0과 1의 호출 횟수 출력
    }

    return 0;
}

// 알고리즘 챌린지17 3일차 문제

#include <stdio.h>

int main() {

    // A, B, C, D가 각각 1부터 10까지 변하는 총 10,000번의 튜플 경우의 수
    for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            for (int c = 1; c <= 10; c++) {
                for (int d = 1; d <= 10; d++) {
                    // 고래는 알을 낳을 수 없으므로 모든 경우에 정답은 없다(-1)
                    printf("-1\n");
                }
            }
        }
    }

    return 0;
}
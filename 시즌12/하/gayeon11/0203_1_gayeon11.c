#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N; // 통화 개수.
    scanf("%d", &N); 

    int time, y_cost = 0, m_cost = 0; // 통화 시간, 영식 요금, 민식 요금.

    // 통화 시간 입력 -> 요금 계산.
    for (int i = 0; i < N; i++) {
        scanf("%d", &time);

        // 영식 요금제: 30초마다 10원.
        y_cost += (time / 30 + 1) * 10;

        // 민식 요금제: 60초마다 15원.
        m_cost += (time / 60 + 1) * 15;
    }

    // 둘 중 더 저렴한 요금제 출력. 
    if (y_cost < m_cost) {
        printf("Y %d\n", y_cost);
    }
    else if (m_cost < y_cost) {
        printf("M %d\n", m_cost);
    }
    else {
        printf("Y M %d\n", y_cost); // 요금이 같을 때 Y M .
    }

    return 0;
}

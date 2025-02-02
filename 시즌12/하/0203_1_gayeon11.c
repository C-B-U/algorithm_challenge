#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N; // ��ȭ ����.
    scanf("%d", &N); 

    int time, y_cost = 0, m_cost = 0; // ��ȭ �ð�, ���� ���, �ν� ���.

    // ��ȭ �ð� �Է� -> ��� ���.
    for (int i = 0; i < N; i++) {
        scanf("%d", &time);

        // ���� �����: 30�ʸ��� 10��.
        y_cost += (time / 30 + 1) * 10;

        // �ν� �����: 60�ʸ��� 15��.
        m_cost += (time / 60 + 1) * 15;
    }

    // �� �� �� ������ ����� ���. 
    if (y_cost < m_cost) {
        printf("Y %d\n", y_cost);
    }
    else if (m_cost < y_cost) {
        printf("M %d\n", m_cost);
    }
    else {
        printf("Y M %d\n", y_cost); // ����� ���� �� Y M .
    }

    return 0;
}
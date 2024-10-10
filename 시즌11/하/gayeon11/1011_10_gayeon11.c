#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int paper[101][101] = { 0 }; 

    for (int k = 0; k < N; k++) {
        int x, y;
        scanf("%d %d", &x, &y);

        for (int i = y; i < y + 10; i++) {
            for (int j = x; j < x + 10; j++) {
                paper[i][j] = 1; // �����̸� ���� �κ��� 1�� ǥ��
            }
        }
    }

    int area = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            if (paper[i][j] == 1) {
                area++; // �����̰� ���� �κ��� ���̸� ����
            }
        }
    }

    printf("%d\n", area);

    return 0;
}
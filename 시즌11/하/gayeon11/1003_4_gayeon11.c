#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int N, a = 0, number = 0, cnt = 0; //number: ���� �� ��
    scanf("%d", &N); //N��° ��ȭ

    while (cnt != N) { //cnt == N�� �Ǹ� ��ȭ �� �� �� ��
        number++;
        a = number;
        while (a != 0) {
            if (a % 1000 == 666) {
                cnt++;
                break;
            }
            else a /= 10; //a = a/10;
        }
    }
    printf("%d", number);
    return 0;
}
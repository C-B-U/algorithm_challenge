#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ���� ����/�������� ���� ���� ��ȯ
int sort_digits(int num, int reverse) {
    int digits[4];

    for (int i = 0; i < 4; i++) {
        digits[i] = num % 10;
        num /= 10;
    }

    // �ܼ��� ���� ����
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 4; j++) {
            if ((reverse && digits[i] < digits[j]) || (!reverse && digits[i] > digits[j])) {
                int temp = digits[i];

                digits[i] = digits[j];
                digits[j] = temp;
            }
        }
    }

    // ���ĵ� ���ڷ� ���� �����
    int result = 0;

    for (int i = 0; i < 4; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}

int kaprekar(int num) {
    int count = 0;

    while (num != 6174) {
        int big = sort_digits(num, 1);  // ��������
        int small = sort_digits(num, 0);  // ��������
        num = big - small;

        count++;
    }

    return count;
}

int main() {
    int T;

    scanf("%d", &T);

    while (T--) {
        int num;
        scanf("%d", &num);
        if (num == 6174) {
            printf("0\n");
        }
        else {
            printf("%d\n", kaprekar(num));
        }
    }

    return 0;
}

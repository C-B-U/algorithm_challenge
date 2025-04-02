#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int extract_middle(int num);
int count_number(int n);

int extract_middle(int num) { // ��� 4�ڸ� ���� �Լ�
    int square = num * num; 
    int middle = (square / 100) % 10000; // ��� 4�ڸ� ����

    // �� �ڸ����� ���� ��� �տ� 0�� �߰��ϱ�
    if (middle < 1000) {
        middle += 10000; // 5 -> 10005ó�� ���� ,
        middle %= 10000; // ���� 1 ���� -> 0005.
    }

    return middle;
}

int count_number(int n) {
    int arr[10000] = { 0 };
    int count = 0;

    while (!arr[n]) { // �ߺ������� ��� ����
        arr[n] = 1; // ���� ���ڰ� �̹� ���Ծ��ٴ� �� ǥ���س���
        count++;
        n = extract_middle(n); // ���� ���� ����
    }
    return count;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) { // �Է� �� ��? && 0�� �ƴѰ�? (0�̸� ���α׷� ���� ��ȣ)
        printf("%d\n", count_number(n));
    }
    return 0;
}

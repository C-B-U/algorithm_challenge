#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ���ĺ�ũ�� 26

int main() {
    char str1[1001], str2[1001];
    int count1[���ĺ�ũ��] = { 0 };
    int count2[���ĺ�ũ��] = { 0 };
    int i, result = 0;

    scanf("%s", str1);
    scanf("%s", str2);

    for (i = 0; str1[i] != '\0'; i++) {
        count1[str1[i] - 'a']++;
    }

    for (i = 0; str2[i] != '\0'; i++) {
        count2[str2[i] - 'a']++;
    }

    // �����ؾ� �� ���� ���� ���.
    for (i = 0; i < ���ĺ�ũ��; i++) {
        result += (count1[i] > count2[i]) ? (count1[i] - count2[i]) : (count2[i] - count1[i]);
    }

    printf("%d\n", result);
    return 0;
}

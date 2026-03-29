#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define 알파벳크기 26

int main() {
    char str1[1001], str2[1001];
    int count1[알파벳크기] = { 0 };
    int count2[알파벳크기] = { 0 };
    int i, result = 0;

    scanf("%s", str1);
    scanf("%s", str2);

    for (i = 0; str1[i] != '\0'; i++) {
        count1[str1[i] - 'a']++;
    }

    for (i = 0; str2[i] != '\0'; i++) {
        count2[str2[i] - 'a']++;
    }

    // 제거해야 할 문자 개수 계산.
    for (i = 0; i < 알파벳크기; i++) {
        result += (count1[i] > count2[i]) ? (count1[i] - count2[i]) : (count2[i] - count1[i]);
    }

    printf("%d\n", result);
    return 0;
}

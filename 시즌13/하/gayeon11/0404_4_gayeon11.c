#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void check_subsequence(char* s, char* t);

void check_subsequence(char* s, char* t) {
    int i = 0, j = 0;

    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++; // s�� ���� ���ڷ� �̵�
        }
        j++; // t�� �׻� ���� ���ڷ� �̵���
    }

    if (s[i] == '\0') {
        printf("Yes\n"); 
        // s�� ��� ���ڰ� t���� ������� �߰�
    }
    else {
        printf("No\n");  
        // i�� �� ���� ���� j�� ���� ����
        // -> s�� ��� ���ڰ� t�� ������� �������� ����!
    }
}

int main() {
    char s[100001], t[100001];

    while (scanf("%s %s", s, t) != EOF) { 
        check_subsequence(s, t);
    }

    return 0;
}

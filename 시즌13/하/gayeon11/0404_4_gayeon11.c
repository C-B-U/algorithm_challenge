#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void check_subsequence(char* s, char* t);

void check_subsequence(char* s, char* t) {
    int i = 0, j = 0;

    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++; // s의 다음 문자로 이동
        }
        j++; // t는 항상 다음 문자로 이동됨
    }

    if (s[i] == '\0') {
        printf("Yes\n"); 
        // s의 모든 문자가 t에서 순서대로 발견
    }
    else {
        printf("No\n");  
        // i가 다 돌기 전에 j가 먼저 끝남
        // -> s의 모든 문자가 t에 순서대로 존재하지 않음!
    }
}

int main() {
    char s[100001], t[100001];

    while (scanf("%s %s", s, t) != EOF) { 
        check_subsequence(s, t);
    }

    return 0;
}

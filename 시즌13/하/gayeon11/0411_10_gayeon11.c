#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char doc[2501]; // doc 문서.
    char word[51];
    int i, j, doc_len, word_len, count = 0;

    // 공백 포함 문자열 입력 받기.
    // " %[^\n]" : 개행 문자 전까지 공백 포함 문자열 입력 받기(문자열 저장이 공백에서 끊기지 않음!!)
    scanf(" %[^\n]", doc);   // 첫 번째 줄 전체 입력 .
    scanf(" %[^\n]", word);  // 두 번째 줄 전체 입력.

    doc_len = strlen(doc);
    word_len = strlen(word);

    for (i = 0; i <= doc_len - word_len;) {
        int match = 1;

        for (j = 0; j < word_len; j++) {
            if (doc[i + j] != word[j]) {
                match = 0;
                break;
            }
        }

        if (match) {
            count++;
            i += word_len;  // 겹치지 않게 건너뛰기 .
        }
        else {
            i++;  // 다음 글자로 이동하기.
        }
    }

    printf("%d\n", count);

    return 0;
}
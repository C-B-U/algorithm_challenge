#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {
    char doc[2501]; // doc ����.
    char word[51];
    int i, j, doc_len, word_len, count = 0;

    // ���� ���� ���ڿ� �Է� �ޱ�.
    // " %[^\n]" : ���� ���� ������ ���� ���� ���ڿ� �Է� �ޱ�(���ڿ� ������ ���鿡�� ������ ����!!)
    scanf(" %[^\n]", doc);   // ù ��° �� ��ü �Է� .
    scanf(" %[^\n]", word);  // �� ��° �� ��ü �Է�.

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
            i += word_len;  // ��ġ�� �ʰ� �ǳʶٱ� .
        }
        else {
            i++;  // ���� ���ڷ� �̵��ϱ�.
        }
    }

    printf("%d\n", count);

    return 0;
}
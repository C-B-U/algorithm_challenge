#include <stdio.h>
#include <string.h>

int main(void) {
    char W[32], S[256];     //암호화에 사용할 단어, 암호화할 문장 
    int seen[26] = { 0 };       //단어 알파벳 중복 없앨때 사용할 배열 

    // 입력
    scanf("%s", W);
    scanf("%s", S);

    // 1) 단어 키 만들기 (중복 제거)
    char key[27];       //중복 제거된 단어 키 
    int klen = 0;
    for (int i = 0; W[i] != '\0'; i++) {    // W[i]가 널 문자 전까지 
        int idx = W[i] - 'A';
        if (seen[idx] == 0) {       //처음 보는 알파벳이면 
            seen[idx] = 1;
            key[klen] = W[i];   //단어 키에 넣기 
            klen++;
        }
    }   
    key[klen] = '\0';           // 마지막에 널 문자 

    // 2) 암호화 표의 "암호 행"(26글자) 만들기
    char cipherRow[26];         //암호화 표의 아랫줄 놈
    int pos = 0;

    // 앞에 key 그대로
    for (int i = 0; i < klen; i++) {
        cipherRow[pos] = key[i];
        pos++;
    }

    // key에 없는 알파벳을 A~Z 순서대로 뒤에 추가
    for (char c = 'A'; c <= 'Z'; c++) {
        int idx = c - 'A';
        if (!seen[idx]) {
            cipherRow[pos++] = c;
        }
    }

    // 3) S 암호화 (평문 A~Z의 인덱스를 그대로 써서 치환)
    for (int i = 0; S[i] != '\0'; i++) {
        putchar(cipherRow[S[i] - 'A']);
    }
    putchar('\n');

    return 0;
}

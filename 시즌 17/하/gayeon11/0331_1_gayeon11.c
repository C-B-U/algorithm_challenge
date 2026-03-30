// 알고리즘 챌린지17 1일차 문제

#include <stdio.h>
#include <string.h> 

int main() {
    char S[1005];
    int i;
    int checkA = 0, checkB = 0, checkC = 0; // A, B, C가 있는지 확인용 변수

    scanf("%s", S);

    int len = strlen(S);

    for (i = 0; i < len; i++) {
        if (S[i] == 'A') {
            checkA = 1;
        }
        if (S[i] == 'B') {
            checkB = 1;
        }
        if (S[i] == 'C') {
            checkC = 1;
        }
    }

    if (checkA == 1) {
        // 1. S에 'A'가 있다면 B, C, D, F를 모두 A로 변경
        for (i = 0; i < len; i++) {
            if (S[i] == 'B' || S[i] == 'C' || S[i] == 'D' || S[i] == 'F') {
                S[i] = 'A';
            }
        }
    }

    else if (checkB == 1) {
        // 2. 'A'가 없고 'B'가 있다면 C, D, F를 모두 B로 변경
        for (i = 0; i < len; i++) {
            if (S[i] == 'C' || S[i] == 'D' || S[i] == 'F') {
                S[i] = 'B';
            }
        }
    }

    else if (checkC == 1) {
        // 3. 'A'와 'B'가 없고 'C'가 있다면 D, F를 모두 C로 변경
        for (i = 0; i < len; i++) {
            if (S[i] == 'D' || S[i] == 'F') {
                S[i] = 'C';
            }
        }
    }

    else {
        // 4. 'A', 'B', 'C'가 모두 없다면 모든 문자를 A로 변경
        for (i = 0; i < len; i++) {
            S[i] = 'A';
        }
    }

    printf("%s\n", S);

    return 0;
}

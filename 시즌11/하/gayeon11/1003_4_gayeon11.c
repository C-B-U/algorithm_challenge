#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    int N, a = 0, number = 0, cnt = 0; //number: 제목에 들어간 수
    scanf("%d", &N); //N번째 영화

    while (cnt != N) { //cnt == N이 되면 영화 수 다 센 거
        number++;
        a = number;
        while (a != 0) {
            if (a % 1000 == 666) {
                cnt++;
                break;
            }
            else a /= 10; //a = a/10;
        }
    }
    printf("%d", number);
    return 0;
}
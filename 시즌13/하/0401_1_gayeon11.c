#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int get_digital_root(char* num) { // 디지털 루트 구하는 함수 정의.
    int sum;

    while (strlen(num) > 1) { // 한 자리 숫자가 될 때까지 반복.
        sum = 0;

        for (int i = 0; num[i] != '\0'; i++) {
            sum += num[i] - '0'; // 문자 -> 정수 변환 ---> 더하기.
        }
        sprintf(num, "%d", sum); 
        // 합계를 다시 문자열로 변환하고,,, 반복.
    }

    return num[0] - '0'; 
    // 최종적으로 나온 한 자리 숫자를 반환하기.
}


int main() {
    char num[1001]; 

    while (1) {
        scanf("%s", num);

        if (num[0] == '0' && num[1] == '\0') break; // 입력의 종료ㅛ조건

        printf("%d\n", get_digital_root(num));
    }

    return 0;
}

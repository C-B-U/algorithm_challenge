#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int extract_middle(int num);
int count_number(int n);

int extract_middle(int num) { // 가운데 4자리 추출 함수
    int square = num * num; 
    int middle = (square / 100) % 10000; // 가운데 4자리 추출

    // 네 자리보다 작은 경우 앞에 0을 추가하기
    if (middle < 1000) {
        middle += 10000; // 5 -> 10005처럼 만듦 ,
        middle %= 10000; // 앞의 1 제거 -> 0005.
    }

    return middle;
}

int count_number(int n) {
    int arr[10000] = { 0 };
    int count = 0;

    while (!arr[n]) { // 중복ㄴㄴ면 계속 진행
        arr[n] = 1; // 현재 숫자가 이미 들어왔었다는 걸 표시해놓기
        count++;
        n = extract_middle(n); // 다음 숫자 생성
    }
    return count;
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) { // 입력 잘 받? && 0이 아닌가? (0이면 프로그램 종료 신호)
        printf("%d\n", count_number(n));
    }
    return 0;
}


// 백준 알고리즘 1065번 '한수' 문제

/*
#include <stdio.h>


int countRepaints(int number) {
    int count = 0;
    
    if (number < 100) {
        count = number;
    }
    else {
        int hundreds = number / 100;
        int tens = (number / 10) % 10;
        int units = number % 10;

        int min = 0 - hundreds/2;
        int max = 4 - hundreds/2;

        count = 99 + (hundreds - 1) * 4;
        
        if(hundreds < 3) {

        }
        else if(2<hundreds<5) {

        }
        else if(4<hundreds<7) {

        }
        else if(6<hundreds<9) {

        }
        else {

        }
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);



    return 0;
}
*/

#include <stdio.h>

// 주어진 수가 한수인지 확인하는 함수
int is_hansu(int n) {
    int a, b, c;

    a = n / 100;       // 백의 자리
    b = (n / 10) % 10; // 십의 자리
    c = n % 10;        // 일의 자리

    return (a - b) == (b - c); // 등차수열인지 확인
}

int main() {
    int N, count = 0;

    // N의 값을 입력받습니다.
    scanf("%d", &N);

    if (N < 100) {
        count = N;
    } else {
        count = 99; // 1부터 99까지는 모두 한수
        for (int i = 100; i <= N; i++) { // 100부터 N까지 검사
            if (is_hansu(i)) {
                count++;
            }
        }
    }

    // 한수의 개수를 출력합니다.
    printf("%d\n", count);

    return 0;
}
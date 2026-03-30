// 백준 알고리즘 '14842번 재홍의 사다리' 문제

/*
#include <stdio.h>

// N이 짝수일 때의 계산 함수
float even(float n, float h) {
    float a = n / 2;
    float sum = 0.0;
    float total;

    // 올바른 합계 계산
    for (int i = 1; i < a; i++) {
        sum += i / a;
    }

    total = sum * h * 2;
    return total;
}

// N이 홀수일 때의 계산 함수
float odd(float n, float h) {
    float sum = 0.0;
    float total;

    // 올바른 합계 계산
    for (int i = 1; i < n; i += 2) {
        sum += i / n;
    }

    total = sum * h * 2;
    return total;
}

int main() {
    float W, H, N, result;

    scanf("%f %f %f", &W, &H, &N);

    if ((int)N % 2 == 0) {
        result = even(N, H);
    } else {
        result = odd(N, H);
    }

    // 소수점 6자리까지 출력
    printf("%.6f", result);

    return 0;
}
*/

#include <stdio.h>

double ResultValue(int a, int b, int n) {
    double result = 0;
    
    if (n % 2 == 0) {
        result = (double)(n - 2) / 4;
    } else {
        result = (double)(n - 1) * (double)(n - 1) / (4 * n);
    }
    
    result *= 2 * b;
    
    return result;
}

int main() {
    int W, H, N;
    double answer;

    scanf("%d %d %d", &W, &H, &N);

    answer = ResultValue(W, H, N);

    printf("%.6f", answer);

    return 0;
}

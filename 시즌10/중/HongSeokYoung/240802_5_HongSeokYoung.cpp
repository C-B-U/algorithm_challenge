// 백준 알고리즘 '14842번 재홍의 사다리' 문제
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

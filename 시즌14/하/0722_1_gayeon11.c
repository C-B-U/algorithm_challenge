#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdio.h>

int main() {
    int A, B, C; // ������ �ֽ� �� -> A������ B��� C���ξ���
    int I, J, K; // Ĭ���� ����

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &I, &J, &K);

    // ������ �ֽ��� ���� �� �ִ� Ĭ���� Ƚ��
    double max_orange = (double)A / I;
    double max_apple = (double)B / J;
    double max_pineapple = (double)C / K;


    double min_cocktail = max_orange;
    if (max_apple < min_cocktail) min_cocktail = max_apple;
    if (max_pineapple < min_cocktail) min_cocktail = max_pineapple;

    // ���� �ֽ� ��
    double remain_orange = A - I * min_cocktail;
    double remain_apple = B - J * min_cocktail;
    double remain_pineapple = C - K * min_cocktail;

    printf("%.6f %.6f %.6f\n", remain_orange, remain_apple, remain_pineapple);

    return 0;
}

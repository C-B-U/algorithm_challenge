#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include <stdio.h>

int main() {
    int A, B, C; // 구매한 주스 양 -> A오렌지 B사과 C파인애플
    int I, J, K; // 칵테일 비율

    scanf("%d %d %d", &A, &B, &C);
    scanf("%d %d %d", &I, &J, &K);

    // 각각의 주스로 만들 수 있는 칵테일 횟수
    double max_orange = (double)A / I;
    double max_apple = (double)B / J;
    double max_pineapple = (double)C / K;


    double min_cocktail = max_orange;
    if (max_apple < min_cocktail) min_cocktail = max_apple;
    if (max_pineapple < min_cocktail) min_cocktail = max_pineapple;

    // 남은 주스 양
    double remain_orange = A - I * min_cocktail;
    double remain_apple = B - J * min_cocktail;
    double remain_pineapple = C - K * min_cocktail;

    printf("%.6f %.6f %.6f\n", remain_orange, remain_apple, remain_pineapple);

    return 0;
}

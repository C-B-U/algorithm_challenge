#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int cumsum, x;
int values[1000001];

int main(void)
{
    int cur, i;

    for (i = 0; i <= 1000000; i++) {
        values[i] = 1; // 모두 자기 자신만을 가질 수 있기 때문에 최소 1의 값들은 가짐 (1원 제외)
    }

    values[1] = 0;

    for (cur = 2; cur <= 1413; cur++) {
        cumsum += cur - 1;
        for (i = 2; cur * i + cumsum <= 1000000; i++) {
            values[cur * i + cumsum]++; // 따라서 해당 표현식으로 가능한 모든 값들에 대해서 경우의 수 하나씩 올려줌
        }
    }

    scanf("%d", &x);
    while (x) {
        printf("%d\n", values[x]);
        scanf("%d", &x);
    }

    return 0;
}
#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    if(N<3 || N>200000) {
        printf("3이상 200000이하의 수를 입력하시오");
    }
    else if(N%2 == 0) {
        printf("Duck");
    }
    else {
        printf("Goose");
    }
    return 0;
}

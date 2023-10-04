#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    }

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }

    return 1;  
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    for (int i = a; i <= b; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}

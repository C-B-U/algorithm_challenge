#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T); 

    while (T > 0) {
        int n;
        scanf("%d", &n);

        int current = n;
        int max_ = n;

        while (current != 1) {
            if (current % 2 == 0) {
                current = current / 2;
            }

            else {
                current = current * 3 + 1;
            }

            if (current > max_) {
                max_ = current;
            }
        }

        printf("%d\n", max_);

        T--;
    }

    return 0;
}
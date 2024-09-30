#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n;
    int result = 0;
    scanf("%d", &n);

    if (n < 100) {
        printf("%d", n);
        return 0;
    }
    result = 99;

    for (int i = 100; i <= n; i++) {
        int target = i;
        int diff = (target % 10);
        int before;
        target /= 10;
        before = (target % 10);
        diff -= before;
        target /= 10;
        
        bool hansu = true;
        while (target) {
            int cur = target % 10;
            if ((before - cur) != diff) {
                hansu = false;
                break;
            }
            before = cur;
            target /= 10;
        }
        if (hansu) {
            ++result;
        }
    }
    printf("%d", result);

    return 0;
}

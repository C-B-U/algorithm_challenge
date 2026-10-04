#include <stdio.h>

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    if (k == 1) {
        printf("YES");
        return 0;
    }

/*
    int early_return;
    if (n * m % 2) {
        early_return = n * m / 2 + 1;
    } else {
        early_return = n * m / 2;
    }
    if (k > early_return) { 
        printf("NO");
        return 0;
    }
*/

    int pivot_x, pivot_y;
    scanf("%d %d", &pivot_x, &pivot_y);

    pivot_x = pivot_x % 2;
    pivot_y = pivot_y % 2;
    int compare = (pivot_x + pivot_y) % 2;

    int target_x, target_y;

    for (int i = 0; i < k - 1; i++) {
        scanf("%d %d", &target_x, &target_y);

        target_x = target_x % 2;
        target_y = target_y % 2;
        
        if ((target_x + target_y) % 2 != compare) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}

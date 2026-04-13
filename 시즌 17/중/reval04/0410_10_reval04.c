#include <stdio.h>
#include <string.h>

int main() {
    int n;
    static char s[500005];
    if (scanf("%d", &n) != 1) return 0;
    scanf("%s", s);

    if (n % 3 != 0) {
        printf("mix\n");
        return 0;
    }

    int h_cnt = 0, o_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') h_cnt++;
        else o_cnt++;
        
        if (o_cnt > h_cnt) {
            printf("mix\n");
            return 0;
        }
    }

    if (h_cnt != 2 * o_cnt) {
        printf("mix\n");
        return 0;
    }

    int rh = 0, ro = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'H') rh++;
        else ro++;
        
        if (ro > rh) {
            printf("mix\n");
            return 0;
        }
    }

    printf("pure\n");
    return 0;
}

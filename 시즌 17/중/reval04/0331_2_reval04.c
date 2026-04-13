#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
    int n, a, b,x,y;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        for (int j = 0; j < b; j++) {
            scanf("%d %d", &x, &y);
        }
        printf("%d\n", a - 1);
    }

}

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>


int main() {
    int n, m, x,a1,a2,a3,a4;
    scanf("%d %d", &n, &m);
    x = 1;
    a1 = n;
    a2 = n / 2;
    a3 = (n + 1) / 2;
    a4 = (n-1) / 3+1;

    if (n == 1 ){
        if (n <= m)x++;
        if (x > 2)x = 2;
        printf("%d", x);
        return 0;
    }
    if (n == 2) {
        if (m >= a1)x +=1;
        if (m >= a2)x += 1;
        if (m >= a3)x += 1;
        if (m >= a1+a4)x += 1;
        if (x > 4)x = 4;
        printf("%d", x);
        return 0;
    }

        if (a1 <= m)x += 1;

        if (a2 <= m)x += 1;

        if (a3 <= m)x += 1;

        if (a4 <= m)x += 1;

        if (a1 + a4 <= m)x += 1;
        if (a2 + a4 <= m)x += 1;
        if (a3 + a4 <= m)x += 1;
        if (x > 8)x = 8;
        printf("%d", x);
}

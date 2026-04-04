#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int res = 1;
    if (m == 0){
        printf("1");
        return 0;
    }
    if (n == 1 && m >= 1){
        res = 2;
        printf("%d", res);
        return 0;
    }
    else if (n == 2){
        if (m == 1) res = 3;
        else if (m >= 2) res = 4;
        printf("%d", res);
        return 0;
    }
    if (n <= m)
        res++;
    if (n/2 <= m)
        res++;
    if ((n+1)/2 <= m)
        res++;
    if (((n-1)/3 + 1) <= m)
        res++;
    if ((n + (n-1)/3 + 1) <= m)
        res++;
    if ((n/2 + (n-1)/3 + 1) <= m)
        res++;
    if (((n+1)/2 + (n-1)/3 + 1) <= m)
        res++;
    
    printf("%d", res);
    
    return 0;
}
#include <stdio.h>

int main() {
    int m, n, q, i;
    scanf("%d %d %d", &m, &n, &q);
    int a[n];
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    
    int res[n];
    for(i=0;i<n;i++) res[i] = 1;
    int temp;
    for(i=1;i<=m;i++){
        printf("? %d %d\n", i, i);
        fflush(stdout);
        scanf("%d", &temp);
        if (temp == 1) res[i-1] = 2;
    }
    
    printf("!");
    for(i=0;i<n;i++) printf(" %d", res[i]);
    
    return 0;
}
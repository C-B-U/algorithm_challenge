#include <stdio.h>

long long int max = -1000000000, min = 1000000000;

void gogo (int n, int a[], int oprt[],
             int p, int m, int t, int d,
             int where, int sum){
    if (where >= n){
        if (sum > max) max = sum;
        if (sum < min) min = sum;
        return;
    }
    
    if (p < oprt[0]) gogo(n, a, oprt, p+1, m, t, d, where+1, sum+a[where]);
    if (m < oprt[1]) gogo(n, a, oprt, p, m+1, t, d, where+1, sum-a[where]);
    if (t < oprt[2]) gogo(n, a, oprt, p, m, t+1, d, where+1, sum*a[where]);
    if (d < oprt[3]) gogo(n, a, oprt, p, m, t, d+1, where+1, sum/a[where]);
}

int main() {
    int n, i;
    int oprt[4];
    scanf("%d", &n);
    
    int a[n];
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    scanf("%d %d %d %d", &oprt[0], &oprt[1], &oprt[2], &oprt[3]);
    
    gogo(n, a, oprt, 0, 0, 0, 0, 1, a[0]);
    
    printf("%lld\n%lld", max, min);
    
    return 0;
}
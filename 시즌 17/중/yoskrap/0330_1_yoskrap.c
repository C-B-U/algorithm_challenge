#include <stdio.h>

int main() {
    long long int n, m, i;
    scanf("%lld %lld", &n, &m);
    
    if (n >= m){
        printf("0");
        return 0;
    }
    
    long long int res = 1;
    for(i=(n/m)*m+1;i<=n;i++){
        res = (res*i)%m;
    }
    printf("%lld", res);
    
    return 0;
}
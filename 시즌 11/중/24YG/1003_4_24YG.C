#include <stdio.h>

int main() {
    int a, b;
    long long sum=0;
    scanf("%d %d",&a,&b);
    if (b>=4) {
        if (a<4) {
            a=4;
        }
        for (int i=a; i<=b; i++) {
            if (i%2==0) {
                sum+=i;
            }
        }
    }
    printf("%lld",sum);
}

#include <stdio.h>
int main() {
    int N;
    long long M;

    scanf("%d %lld", &N, &M);

    long long A;
    long long total = 0;

    for(int i=0; i<N; i++) {
        scanf("%lld", &A);

        total+=(A-1);
    }

    if(total>=M) printf("DIMI");
    else printf("OUT");
    
    return 0;
}

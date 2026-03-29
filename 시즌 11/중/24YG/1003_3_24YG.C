#include <stdio.h>
#include <stdlib.h>

int main() {
        int N, K, A, B ;
        int num = 0;
        int day = 0 ;
        scanf("%d %d %d %d",&N,&K,&A,&B);

        int pot[N]={};
        for (int i=0; i<N; i++) {
                pot[i]=K;
        }

        while (1) {
                for (int k=0; k<A; k++) {
                        pot[num] += B;
                        num++ ;
                        if (N == num) {
                                num=0;
                        }
                }
                for (int l=0; l<N; l++) {
                        pot[l] -= 1;
                        if (pot[l] == 0) {
                                printf("%d",day+1);
                                exit(0);
                        }
                }
                day += 1;
        }
}

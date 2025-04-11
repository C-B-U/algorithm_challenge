#include <stdio.h>

int main() {
    int n, t1, t2, i;
    scanf("%d", &n);
    int timeC = 0, timeP = 0;
    
    for(i=0;i<n;i++){
        scanf("%d %d", &t1, &t2);
        if (timeP < t2){
            timeC += t2-timeP;
            timeP = t1;
        }
        else {
            timeP += -t2 + t1;
        }
    }
    
    printf("%d", timeC);
}
#include <stdio.h>

int main(){
    int n, count = 0, p;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int state = 1;
        scanf("%d", &p);
        if((p%2==0 && p!=2) || p==1) continue;
        for (int j = 3; j <= p/3; j+=2){
            if(p%j==0) state = 0;
        }
        if(state) count++;
    }
    printf("%d\n", count);
    return 0;
}

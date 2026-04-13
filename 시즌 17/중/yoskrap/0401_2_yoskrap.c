#include <stdio.h>

int main(){
    int t;
    scanf("%d", &t);
    
    for(int i=0;i<t;i++){
        int n, m;
        scanf("%d %d", &n, &m);
        int a, b;
        for(int j=0;j<m;j++)
            scanf("%d %d", &a, &b);
        printf("%d\n", n-1);
    }
    
    return 0;
}
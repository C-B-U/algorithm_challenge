#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    int list[m];
    scanf("%d", &list[0]);
    int max = list[0];
    
    int i, temp;
    for(i=1;i<m;i++){
        scanf("%d", &list[i]);
        temp = (list[i]-list[i-1])/2;
        if((list[i]-list[i-1])%2 != 0) temp++;
        if(temp > max) max = temp;
    }
    
    if((n-list[m-1]) > max) max = n-list[m-1];
    
    printf("%d", max);
    
    return 0;
}
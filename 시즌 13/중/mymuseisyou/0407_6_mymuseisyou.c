#include <stdio.h>

int main() {
    int n1, n2, t;
    char antemp;
    int i, j;
    scanf("%d %d", &n1, &n2);
    int len = n1+n2;
    
    char c1[n1], c2[n2];
    scanf("%s", c1);
    scanf("%s", c2);
    char ant[len+1];
    ant[len] = '\0';
    for(i=0;i<n1;i++) ant[i] = c1[n1-i-1];
    for(i=n1;i<len;i++) ant[i] = c2[i-n1];
    
    scanf("%d", &t);
    
    int d[len];
    for(i=0;i<n1;i++) d[i] = 1;
    for(i=n1;i<len;i++) d[i] = -1;
    
    for(i=0;i<t;i++){
        for(j=0;j<len-1;j++){
            if (d[j] == 1 && d[j+1] == -1){
                d[j] = -1;
                d[j+1] = 1;
                
                antemp = ant[j];
                ant[j] = ant[j+1];
                ant[j+1] = antemp;
                
                j++;
            }
        }
    }
    
    printf("%s", ant);
    
    return 0;
}
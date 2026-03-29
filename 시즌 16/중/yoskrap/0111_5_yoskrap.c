#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    int i, j;
    int ch[17] = {0}; //2^17=131072, 0이면 소수
    ch[0] = 1;
    ch[1] = 1;
    for(i=2;i<17;i++){
        for(j=2;j*j<=i;j++){
            if(i%j == 0){
                ch[i] = 1;
                break;
            }
        }
    }
    
    int res = 0, count, temp;
    for(i=a;i<=b;i++){
        count = 0;
        temp = i;
        for(j=2;j*j<=temp;j++){
            if(temp%j == 0){
                count++;
                temp /= j;
                j--;
            }
        }
        if(temp > 0) count++;
        if(ch[count] == 0) res++;
    }
    
    printf("%d", res);
    
    return 0;
}
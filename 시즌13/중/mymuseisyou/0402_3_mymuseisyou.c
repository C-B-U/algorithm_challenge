#include <stdio.h>

int main() {
    int n, x, y, mx, my, count = 0;
    int i, j, k;
    int map[100][100] = { 0, };
    scanf("%d", &n);
    
    for(i=0;i<n;i++){
        scanf("%d %d", &x, &y);
        mx = x+9;
        if(mx/100 >= 1) mx = 99;
        my = y+9;
        if(my/100 >= 1) my = 99;
        
        for(j=(x-1);j<mx;j++){
            for(k=(y-1);k<my;k++){
                if(map[j][k] != 1){
                    map[j][k] = 1;
                    count++;
                }
            }
        }
    }
    
    printf("%d", count);
}
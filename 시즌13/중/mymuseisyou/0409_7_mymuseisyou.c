#include <stdio.h>

int len = 0;

void search (int f, int r, int n, int m, int k, int temp[], int *count){
    int i, tk;
    if(n == m) {
        tk = 0;
        for(i=0;i<m;i++){
            if(temp[i] <= m) tk++;
        }
        if(tk >= k) (*count)++;
        len++;
        return;
    }
    for(i=f;i<=r;i++){
        temp[n] = i;
        search(i+1, r, n+1, m, k, temp, count);
    }
}

int main() {
    int n, m, k, i;
    int count = 0;
    double result;
    scanf("%d %d %d", &n, &m, &k);
    
    int temp[m];
    
    for(i=1;i<=n-(m-1);i++){
        temp[0] = i;
        search(i+1, n, 1, m, k, temp, &count);
    }
    
    result = (double)count/(double)len;
    
    printf("%.10f", result);
}
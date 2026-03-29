#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b){
    return (*(int*)a - *(int*)b);
}

void dfs(int map[][1001], int rear[], int n, int v, int check[]){
    if(check[v] == 1) return;
    
    printf("%d ", v);
    check[v] = 1;
    int i;
    
    for(i=0;i<rear[v];i++){
        dfs(map, rear, n, map[v][i], check);
    }
}

void bfs(int map[][1001], int rear[], int n, int v, int check[]){
    int f=0, r=0, i;
    int queue[1001];
    queue[r++] = v;
    check[v] = 1;
    
    while(f<r){
        printf("%d ", queue[f]);
        for(i=0;i<rear[queue[f]];i++){
            if(check[map[queue[f]][i]] == 0){
                queue[r++] = map[queue[f]][i];
                check[map[queue[f]][i]] = 1;
            }
        }
        f++;
    }
}

int main() {
    int n, m, v, i;
    int temp1, temp2;
    scanf("%d %d %d", &n, &m, &v);
    int map[1001][1001];
    int rear[1001] = { 0, };
    
    int check[1001][1001] = { 0, };
    int dcheck[1001] = { 0, };
    int bcheck[1001] = { 0, };
    
    for(i=0;i<m;i++){
        scanf("%d %d", &temp1, &temp2);
        if(check[temp1][temp2] == 0 || check[temp2][temp1] == 0){
            map[temp1][rear[temp1]++] = temp2;
            map[temp2][rear[temp2]++] = temp1;
            check[temp1][temp2] = 1;
            check[temp2][temp1] = 1;
        }
    }
    
    for(i=1;i<=n;i++){
        qsort(map[i], rear[i], sizeof(int), compare);
    }
    
    dfs(map, rear, n, v, dcheck);
    printf("\n");
    bfs(map, rear, n, v, bcheck);
    
    return 0;
}
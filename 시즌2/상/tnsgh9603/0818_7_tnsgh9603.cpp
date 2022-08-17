#include<cstdio>
int p[100001][31],n[100001],N,K,M;
int main(){
    scanf("%d%d%d",&N,&K,&M);--M;
    for(int i=0;i<N;++i)scanf("%d",&n[i]);
    for(int i=1;i<=K;++i)scanf("%d",&p[i][0]);
    for(int j=1;j<31;++j)for(int i=1;i<=K;++i)p[i][j]=p[p[i][j-1]][j-1];
    for(int i=0;i<N;++i){
        for(int j=0;(1<<j)<=M;++j)if(M&(1<<j))n[i]=p[n[i]][j];
        printf("%d ",n[i]);
    }
}

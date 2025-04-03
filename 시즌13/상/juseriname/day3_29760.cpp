#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
/**
층 올라가는 비용이 100이라 층 올라가면 다시 내려오는게 쉽지 않음.
-> 한 층에서 다 처리하고 올라가기.
-> 한 층에서의 맨 처음과 끝만 중요함.
-> 중간에 있는 값은 생각 안해도 됨.

윗층은 1,100인데 지금 40에서 끝났다!
->왼쪽, 오른쪽 길 비교해서 어느쪽으로 가는게 비용 더 적은지 확인하고 가기.
**/
int togo[1001][2]; // [floor][min,max]
int dp[1001][2]; // [floor][left,right]
int maxx=0;

int dfs(int x,int y,bool dir)
{
    if(x==maxx+1) return -100; //다돌았다!
    if(dp[x][dir]!=-1) return dp[x][dir];
    if(togo[x][1]==0) {//해당층 없음
        dp[x][dir]=dfs(x+1,y,dir)+100;
        //cout << x << "n  " << dp[x][dir] << endl; //test
    }
    else {
        dp[x][dir]=min(dfs(x+1,togo[x][0],0) + abs(togo[x][1]-y),
                       dfs(x+1,togo[x][1],1) + abs(togo[x][0]-y))
                       +100+togo[x][1]-togo[x][0];
        //cout << dfs(x+1,togo[x][0],0)+abs(togo[x][1]-y) << ' '
        //    << dfs(x+1,togo[x][1],1)+abs(togo[x][0]-y) << ' '
        //    << togo[x][1]-togo[x][0] << endl; //test
    }
    return dp[x][dir];
}

int main()
{
    int n,h,w;
    cin >> n >> h >> w;
    for(int i=0;i<=h;i++)
    {
        togo[i][0]=w;
    }
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y; //x->층,y->호
        maxx=max(x,maxx);
        //cout <<"before: " << min(togo[x][0],x) << ' ' << y << endl;
        togo[x][0]=min(togo[x][0],y);
        togo[x][1]=max(togo[x][1],y);
        //cout <<"after: " << togo[x][0] << ' ' << togo[x][1] << endl;

    }/*
    for(int i=0;i<w;i++)
    {
        cout << togo[i][0] << ' ' << togo[i][1] << endl;
    }*/
    memset(dp,-1,sizeof(dp));
    cout << dfs(1,1,0) << '\n';
    //왜 값이 이상하? -> visited 체크 잘 못하고 있었음. 바꾸니 해결...
    return 0;
}

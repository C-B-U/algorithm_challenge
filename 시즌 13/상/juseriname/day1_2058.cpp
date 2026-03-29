#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int atom[201];
int plu[201];
int dp[201][2];
vector<int> v[201];

int dfs(int cur,int last,bool flag){ //flag==1 -> 방금 갔다옴,flag==0 -> 방금 안갔다옴
    auto& hap = dp[cur][flag]; //왜빨라지는거임???????
    if(hap != -1) return hap;
    hap = flag ? atom[cur] : 0;
    for(const auto& next : v[cur]) //const auto& 읽기전용 속도차?
    {
        if(next == last) continue; //다시 올라가는거 방지
        if(flag) hap += dfs(next,cur,0);
        else hap += max(dfs(next,cur,0),dfs(next,cur,1));
    }
    return hap;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        cin >> atom[i];
    }
    for(int i=0;i<m;i++)
    {
        cin >> plu[i];
    }
    sort(atom,atom+n); //오름차순

    for(int i=0;i<n;i++) //간선 잇기 작업
    {
        for(int j=0;j<m;j++)
        {
            auto index = lower_bound(atom,atom+n,atom[i]-plu[j]) - atom; //대응하는 원소가 있나 찾기
            ///새로 알게된점:find()함수는 선형탐색, lower_bound()는 이진탐색이라 더 빠름.
            if(index != n && atom[index] == atom[i]-plu[j]) //최대(없음) 아니고, 실제로 있나 확인
            {
                v[i].push_back(index); // 큰거 -> 작은거
                v[index].push_back(i); // 작은거 -> 큰거
            }
        }
    }

    memset(dp,-1,sizeof(dp));//dp초기화
    cout << max(dfs(0,-1,0),dfs(0,-1,1)) << '\n';
    return 0;
}

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int N , M , R;
vector<int>graph[100001];
int visited[100001];
int answer[100001];
int cnt=0;

void dfs(int start){
    visited[start] = 1;

    answer[start]=++cnt;
    //cout << cnt << "\n";
    for(int i = 0 ; i<graph[start].size();i++){
        int next = graph[start][i];
        if(visited[next]==0){
            dfs(next);
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> R;
    for(int i = 0 ; i<M;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    for(int i = 1 ; i <= N;i++){
        std::sort(graph[i].begin(), graph[i].end(),greater<int>());
    }

    dfs(R);

    //cout << "\n";

    for(int i = 1 ; i <= N;i++){
        cout << answer[i]<<"\n";
    }

}
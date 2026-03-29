#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M,R;

vector<int>v1[100001];
int visited[100001];
int result[100001];


int cnt = 0;
void bfs(int start){
    queue<int>q;
    visited[start]=1;
    q.push(start);

    while(!q.empty()) {
        //cout << cnt<<"\n";
        int x = q.front();
        cnt++;
        result[x]=cnt;
        q.pop();
        for (int i = 0; i < v1[x].size(); i++) {
            int y = v1[x][i];
            if (!visited[y]) {
                //cout << y << "\n";
                q.push(y);
                visited[y] = 1;
            }
        }
    }
}





int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N >> M >> R;

    for (int i = 0 ; i < M;i++){
        int a ,b ;
        cin>> a>> b;
        v1[a].push_back(b);
        v1[b].push_back(a);
    }

    for (int i = 1; i<=N ; ++i) {
        std::sort(v1[i].begin(), v1[i].end(),greater<>());
    }

        bfs(R);
        for(int i = 1 ; i <= N;i++){
            cout << result[i]<<"\n";
        }
}

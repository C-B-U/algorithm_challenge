#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int start, const vector<vector<int>> &graph, vector<bool> &visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    int answer = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();

        for (int next : graph[node]) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
                answer++;
            }
        }
    }
    return answer;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        vector<vector<int>> graph(1001);
        vector<bool> visited(1001,false);
        int n, m; cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u); 
        }
    cout << bfs(1,graph,visited) << ' ';
    }
}
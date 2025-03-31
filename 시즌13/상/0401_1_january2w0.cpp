#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, M;
vector<int> atom;
vector<int> pton;
unordered_map<int, bool> visit;
unordered_map<int, vector<int>> dp;

void dfs(int cur)
{
    visit[cur] = true;
    dp[cur][1] = cur;

    for (int gap : pton) {
        for (int nxt : { cur + gap, cur - gap }) {
            if (visit.count(nxt) && !visit[nxt]) {
                dfs(nxt);
                dp[cur][0] += max(dp[nxt][1], dp[nxt][0]);
                dp[cur][1] += dp[nxt][0];
            }
    }   }
}

int main()
{
    cin >> N >> M;

    atom.resize(N);
    pton.resize(M);

    for (int& e : atom) cin >> e;
    for (int& e : pton) cin >> e;
    for (int e : atom) visit[e] = false, dp[e] = { 0, 0 };

    int e = atom[0];

    dfs(e);
    cout << max(dp[e][0], dp[e][1]) << endl;

    return 0;
}

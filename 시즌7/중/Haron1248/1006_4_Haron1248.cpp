#include <iostream>
#include <vector>
#include <stack>
#include <set>
using namespace std;

int main()
{
    int n;
    vector<int> adj[101];

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            cin >> t;
            if (t == 1)
                adj[i].push_back(j);
        }
    }

    for (int i = 1; i <= n; i++) {
        set<int> visited;
        stack<int> s;
        string binaryString(n, '0');
        s.push(i);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            for (int j = 0; j < adj[current].size(); j++) {
                int neighbor = adj[current][j];
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    s.push(neighbor);
                    binaryString[neighbor - 1] = '1';
                }
            }
        }

        for (int k = 0; k < n; k++) {
            cout << binaryString[k];
            if (k != n - 1)
                cout << ' ';
            else
                cout << '\n';
        }
    }
}

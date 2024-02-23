#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void DFS(vector<vector<int>>& v, vector<bool>& b, int i, int m, int& cnt)
{
    if (i == m) return;
    if (i != -1 && v[i].size() == 0 || v[i].size() == 1 && v[i][0] == m)
    {
        cnt++;
        return;
    }

    for (int idx : v[i])
    {
        if (b[idx]) continue;
        b[i] = true;
        DFS(v, b, idx, m, cnt);
    }
}

int main()
{
    unsigned int n;
    int tmp, m, cnt = 0;
    cin >> n;
    vector<vector<int>> v{ n};
    vector<bool> b(n, false);
    vector<bool> root(n, false);
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        if (tmp == -1) root[i] = true;
        else v[tmp].push_back(i);
    }
    
    cin >> m;
    
    for (int i = 0; i < root.size(); ++i)
        if (root[i])
            DFS(v, b, i, m, cnt);
    
    cout << cnt << endl;
}

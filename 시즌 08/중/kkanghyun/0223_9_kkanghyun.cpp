#include <iostream>
#include <vector>

using namespace std;
int cnt;

void Dfs(int parent, const vector<vector<int>>& tree)
{
    if (tree[parent].empty() == false)
    {
        for (int i = 0; i < tree[parent].size(); ++i)
        {
            Dfs(tree[parent][i], tree);
        }
    }
    else
    {
        cnt++;
    }
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> tree(N, vector<int>());

    vector<int> v;

    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        v.push_back(num);
    }

    int d;
    cin >> d;

    int root = -1;
    for (int i = 0; i < N; ++i)
    {
        if (v[i] == -1)
        {
            root = i;
            continue;
        }

        if (i != d)
        {
            tree[v[i]].push_back(i);
        }
    }

    if (root != d)
    {
        Dfs(root, tree);
    }

    cout << cnt;
}
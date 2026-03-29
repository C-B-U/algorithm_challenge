#include <iostream>
#include <array>

using namespace std;

array<int, 1000001> parent;

int getParent(int num) 
{
    if (parent[num] == num)
        return num;

    parent[num] = getParent(parent[num]);

    return parent[num];
}

void unionParent(int a, int b) 
{
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa > pb)
    {
        parent[pa] = pb;
    }
    else
    {
        parent[pb] = pa;
    }
}

void findParent(int a, int b) 
{
    int pa = getParent(a);
    int pb = getParent(b);

    if (pa == pb)
    {
        cout << "YES" << '\n';
    }
    else
    {
        cout << "NO" << '\n';
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i) 
    {
        bool bFind;
        int a, b;
        cin >> bFind >> a >> b;

        if (bFind)
        {
            findParent(a, b);
        }
        else 
        {
            unionParent(a, b);
        }
    }
}
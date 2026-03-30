#include <iostream>
using namespace std;

int users[1000001];

int FindParent(int idx)
{
    if (users[idx] == idx)
        return idx;

    return users[idx] = FindParent(users[idx]);
}

void Union(int a, int b)
{
    a = FindParent(a);
    b = FindParent(b);

    users[a] = b;
}

int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;

    int n;  // 유저의 수
    int k, m, a, b, u, v;
    for (int i = 1; i <= T; ++i) 
    {
        cin >> n;   // 유저의 수

        // 부모배열 초기화
        for (int j = 0; j < n; ++j)
        {
            users[j] = j;
        }

        cin >> k;   // 친구 관계의 수
        for (int j = 0; j < k; ++j)
        {
            cin >> a >> b;  // 친구 관계
            if (FindParent(a) != FindParent(b)) 
                Union(a, b);
        }

        cin >> m;   // 미리 구할 쌍의 수

        cout << "Scenario " << i << ":" << '\n';
        for (int j = 0; j < m; ++j) 
        {
            cin >> u >> v;  // 구해야하는 쌍

            if (FindParent(u) == FindParent(v))
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        
        cout << '\n';
    }
}
#include <iostream>
using namespace std;

bool bTrue[26][26];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    char a, b;
    string s;   // is
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> s >> b;

        bTrue[a - 'a'][b - 'a'] = true;
    }

    for (int i = 0; i < 26; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            for (int k = 0; k < 26; ++k)
            {
                if (bTrue[j][k])
                    continue;

                bTrue[j][k] = bTrue[j][i] && bTrue[i][k];
            }
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> s >> b;

        char c = bTrue[a - 'a'][b - 'a'] ? 'T' : 'F';
        cout << c << '\n';
    }
}
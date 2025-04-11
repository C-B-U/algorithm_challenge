#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i, N, M, P[10];

    cin >> N;
    for (i = 0; i < N; i++)  cin >> P[i];
    cin >> M;

    int md1, mp1 = 50;

    for (i = 1; i < N; i++) {
        if (P[i] <= mp1) mp1 = P[i], md1 = i;
    }

    if (mp1 > M) { cout << 0; return 0; }

    int md = (P[0] < mp1) ? 0 : md1;
    int mp = min(P[0], mp1);
    int len = 1 + (M - mp1)/mp;
    int rem = M - mp1 - (len-1)*mp;

    vector<int> ans(len, md); ans[0] = md1;

    for (i = 0; i < len; i++)
    {
        int cur = ans[i];

        for (int d = N-1; d > 0; d--)
        {
            if (P[d] <= rem + P[cur]) {
                ans[i] = d;
                rem -= (P[d] - P[cur]);
                break;
            }
        }
    }

    for (int d : ans) cout << d;

    return 0;
}

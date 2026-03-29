#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[303030] = { 0 };
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, s, height, cost, start, end, mid, ans_idx;
    vector <pair <int, int> > v;
    cin >> n >> s;
    v.push_back({ -2e9,0 }); //0번 인덱스 
    for (int i = 1; i <= n; i++)
    {
        cin >> height >> cost;
        v.push_back({ height,cost });
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; i++)
    {
        start = 0;
        end = i - 1;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (v[mid].first <= v[i].first - s)
            {
                ans_idx = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        dp[i] = max(dp[i - 1], dp[ans_idx] + v[i].second);
    }
    cout << dp[n];
}
// [출처] 전시장 (백준 2515)|작성자 jihwanmoon0319
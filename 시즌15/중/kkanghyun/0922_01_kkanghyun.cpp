#include <iostream>
using namespace std;

int pie[200002];
int sum[200002];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; ++i)
    {
        cin >> pie[i];
    }

    for (int i = 1; i <= N; ++i)
    {
        pie[i + N] = pie[i];
    }

    sum[1] = pie[1];

    for (int i = 2; i <= 2 * N; ++i)
    {
        sum[i] = sum[i - 1] + pie[i];
    }

    int ans = 0;
    for (int i = K; i <= 2 * N; ++i)
    {
        ans = max(ans, sum[i] - sum[i - K]);
    }

    cout << ans;
}
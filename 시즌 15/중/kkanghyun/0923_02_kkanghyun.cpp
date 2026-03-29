#include <iostream>
#include <numeric>
using namespace std;

int T[16];  // 상담 기간
int P[16];  // 금액
int dp[16]; // i일에 받을 수 있는 금액의 최댓값

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        cin >> T[i] >> P[i];

        // 날짜를 초과하지 않는다면 최댓값 갱신 -> 현재까지 금액 + 이번상담이 끝난 후 금액
        if (i + T[i] <= N)
            dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);

        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[N];
}
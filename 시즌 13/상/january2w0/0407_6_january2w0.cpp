#include <iostream>

using namespace std;

int main()
{
    int i, j, T, N, M;
    cin >> T;

    while (T--)
    {
        int V[20], dp[10001] = { 1 };

        cin >> N;
        for (i = 0; i < N; i++) cin >> V[i];
        cin >> M;

        for (i = 0; i < N; i++) {
            for (j = V[i]; j <= M; j++) {
                dp[j] += dp[j - V[i]];
        }   }

        cout << dp[M] << endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> dp;
	dp.resize(N + 1);

	dp[1] = 0;
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[N];
}
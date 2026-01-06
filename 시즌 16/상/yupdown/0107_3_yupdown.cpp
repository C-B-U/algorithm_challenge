#include <bits/stdc++.h>

using namespace std;
int memo[1024][2][3];
constexpr int MOD = 1000000;

int main()
{
	int n;
	cin >> n;
	memo[0][0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		// 출석 case
		memo[i][0][0] = (
			memo[i - 1][0][0] +
			memo[i - 1][0][1] +
			memo[i - 1][0][2]) % MOD;
		memo[i][1][0] = (
			memo[i - 1][1][0] +
			memo[i - 1][1][1] +
			memo[i - 1][1][2]) % MOD;
		// 지각 case
		memo[i][1][0] = (
			memo[i][1][0] +
			memo[i - 1][0][0] +
			memo[i - 1][0][1] +
			memo[i - 1][0][2]) % MOD;
		// 결석 case
		memo[i][0][2] = memo[i - 1][0][1];
		memo[i][0][1] = memo[i - 1][0][0];
		memo[i][1][2] = memo[i - 1][1][1];
		memo[i][1][1] = memo[i - 1][1][0];
	}
	int result = 0;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 3; ++j) {
			result = (result + memo[n][i][j]) % MOD;
		}
	}
	cout << result;
}
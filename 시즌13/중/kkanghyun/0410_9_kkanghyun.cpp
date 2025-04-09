#include <iostream>
using namespace std;

int arr[100'001][2];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int D, V;
	for (int i = 1; i <= N; ++i)
	{
		cin >> D >> V;

		arr[i][0] = D + arr[i - 1][0];
		arr[i][1] = V + arr[i - 1][1];
	}

	int ans = 0;
	for (int i = N; i > 0; --i)
	{
		ans = max(ans, arr[i][1] - arr[i - 1][0]);
	}

	cout << ans;
}
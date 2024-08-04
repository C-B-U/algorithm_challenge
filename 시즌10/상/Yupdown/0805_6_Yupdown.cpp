#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int memo[1000001];

int main()
{
	int n;
	cin >> n;
	v.push_back(1);
	memset(memo, 1, sizeof(memo));
	for (int i = 1; v.back() <= n; ++i)
		v.push_back(v.back() + i * 4 + 1);
	memo[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int vp : v)
		{
			if (i + vp <= n)
				memo[i + vp] = min(memo[i + vp], memo[i] + 1);
		}
	}
	cout << memo[n];
}
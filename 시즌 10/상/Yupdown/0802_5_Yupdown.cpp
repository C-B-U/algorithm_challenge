#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int memo[51];

int get_value(const string& dst, const string& src, int p)
{
	int table[26];
	memset(table, 0, sizeof(table));
	int v = 0;
	for (int i = 0; i < src.size(); ++i)
	{
		v += src[i] != dst[p + i];
		table[src[i] - 'a']++;
		table[dst[p + i] - 'a']--;
	}

	for (int i = 0; i < 26; ++i)
	{
		if (table[i] != 0)
			return -1;
	}
	return v;
}

int main()
{
	FASTIO();

	int n;
	string dst, src[50];

	cin >> dst >> n;
	for (int i = 0; i < n; ++i)
		cin >> src[i];

	memset(memo, -1, sizeof(memo));
	memo[0] = 0;
	for (int i = 0; i < dst.length(); ++i)
	{
		if (memo[i] < 0)
			continue;
		for (int j = 0; j < n; ++j)
		{
			int m = src[j].length();
			if (i + m > dst.length())
				continue;
			int v = get_value(dst, src[j], i);
			if (v < 0)
				continue;
			if (memo[i + m] < 0)
				memo[i + m] = INT_MAX;
			memo[i + m] = min(memo[i + m], memo[i] + v);
		}
	}

	cout << memo[dst.length()];
}
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// LIS(가장 긴 증가하는 부분 수열)로 변형하여 문제를 풀이
// 여기서의 수열의 각 원소 A[i] 는 i번째 위치의 스위치와 연결되어 있는 전구의 위치가 된다.
// n <= 10000 인 경우 O(n^2) 시간복잡도 알고리즘을 사용하여도 TLE가 발생하지 않는다.

int table[10001][2];
int in[10000];
int memo[10000];
int el[10000];

int main()
{
	FASTIO();
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		table[v][0] = i;
		table[i][1] = v;
	}

	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		in[n - i - 1] = table[v][0];
	}

	for (int i = 0; i < n; ++i)
	{
		pair vmax{ 0, -1 };
		for (int j = 0; j < i; ++j)
		{
			if (in[i] < in[j] && memo[j] >= vmax.first)
				vmax = { memo[j], j };
		}
		memo[i] = vmax.first + 1;
		el[i] = vmax.second;
	}

	int r = distance(memo, max_element(memo, memo + n));
	vector<int> ret;
	for (; r >= 0; r = el[r])
		ret.push_back(table[in[r]][1]);
	sort(ret.begin(), ret.end());

	cout << ret.size() << '\n';
	for (int r : ret)
		cout << r << ' ';
}
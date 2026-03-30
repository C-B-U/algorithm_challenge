#include <bits/stdc++.h>

using namespace std;
int memo[1000001];

int main()
{
	int n;
	cin >> n;
	queue<int> q;
	q.push(0);
	while (!memo[n])
	{
		int i = q.front();
		q.pop();
		for (int j = i + 1, k = 1; j <= n; j = j + k++ * 4 + 1)
		{
			if (memo[j])
				continue;
			memo[j] = memo[i] + 1;
			q.push(j);
		}
	}
	cout << memo[n];
}
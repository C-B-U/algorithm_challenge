#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
long long table[200000];
pair<long long, long long> delta[200000];

// 최솟값 찾기(https://www.acmicpc.net/problem/11003) 응용 문제
// 누적 합 테크닉을 이용하여 특정 위치에서 수열에서 얻을 수 있는 이익이 얼마인지 저장한다.
// 한쪽 피벗에 대한 최대 이익을 Priority Queue로 저장한 후, 다른 피벗을 이동시키면서 최대 이익을 꺼내며 최댓값을 갱신한다.
// 만약 꺼낸 최대 이익이 k 보다 멀 경우 무시한다.
// 모든 수열의 원소가 빔의 영향을 받아 반전된 경우도 고려해서 알고리즘을 작성한다.

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	for (int i = 1; i < n; ++i)
		delta[i].first = delta[i - 1].first - table[i - 1] * 2;
	for (int i = n - 2; i >= 0; --i)
		delta[i].second = delta[i + 1].second - table[i + 1] * 2;
	priority_queue<pair<long long, int>> pq;
	long long delta_max = LLONG_MIN;
	pair<int, int> ret;
	pq.emplace(delta[n - 1].second, 1 - n);
	for (int lhs = n - 1; lhs >= 0; --lhs)
	{
		if (lhs > 0)
			pq.emplace(delta[lhs - 1].second, 1 - lhs);
		while (!pq.empty() && -pq.top().second - lhs > k)
			pq.pop();
		pq.emplace(delta[lhs].second, -lhs);
		auto [rhs_delta, rhs] = pq.top();
		rhs = -rhs;
		long long delta_cur = delta[lhs].first + rhs_delta;
		if (delta_cur >= delta_max)
		{
			delta_max = delta_cur;
			ret = make_pair(lhs, rhs);
		}
	}
	long long vsum = accumulate(table, table + n, 0);
	cout << vsum + delta_max << "\n";
	cout << ret.first + 1 << " " << ret.second + 1;
}
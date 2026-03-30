#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

// 주어진 사람들의 실력 차가 최소가 되도록 팀을 만드려면, 사람을 실력 순으로 정렬하고, 인접한 4명을 각각 팀으로 만들면 된다.
// 그런데, 사람 수가 4의 배수가 아닐 수도 있다. 이럴 땐 N % 4명의 사람들은 무조건 제외된다.
// 제외되는 사람을 먼저 조합으로 지정하고, 남은 사람들의 실력 차이를 계산하기엔 최대 1e+5C3의 경우의 수가 나오므로, 다이나믹 프로그래밍으로 해결해야 한다.

// memo[i][c] = 정렬된 사람들 중 i번째 사람부터 N - 1번째 사람까지 c명을 제외하고 팀을 짜는 경우의 최소 실력 차이
// 여기서, 제외되는 사람들의 번호를 알아야 하므로 memo[i][c]의 반환값은 std::vector<int>로 한다.
// 첫번째 원소는 실력 차이, 나머지 원소는 제외되는 사람들의 번호이다.
// std::vector<int>는 std::lexicographical_compare를 기본적으로 사용하므로, 이를 이용하여 실력 차이를 기준으로 쉽게 비교할 수 있다.

using namespace std;
constexpr int INF = 0x7FFFFFFF;
pair<int, int> table[100000];
vector<int> memo[100000][3];

vector<int> solution(int n, int i, int c)
{
	if (i == n)
		return vector<int>(1, 0);
	if (c < 0)
		return vector<int>(1, INF);
	if (memo[i][c][0] < INF)
		return memo[i][c];
	auto ret = solution(n, i + 1, c - 1);
	ret.push_back(table[i].second);
	if (i + 3 < n)
	{
		auto v = solution(n, i + 4, c);
		v[0] += table[i + 3].first - table[i].first;
		ret = min(ret, v);
	}
	return memo[i][c] = ret;
}

int main()
{
	FASTIO();
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> table[i].first;
		table[i].second = i;
		for (int j = 0; j <= n % 4; ++j)
			memo[i][j] = vector<int>(1, INF);
	}
	sort(table, table + n);
	auto ret = solution(n, 0, n % 4);
	for (int v : ret)
		cout << v << "\n";
}
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int height[200000];
vector<int> edge[200000];

// height[i]는 모두 정수이기 때문에, 물이 이동하는 경로에 대한 Deterministic한 연산은 모두 정수부에 의해 결과가 달라진다.
// H_b+(H_a-H_b)/2의 소숫점 부분을 고려하지 않아도 가능하기 때문에 정수 나눗셈을 적용해도 된다.

int solution(int node, int node_prev)
{
	int height_max = height[node];
	bool flag = false;
	for (int node_next : edge[node])
	{
		if (node_next == node_prev)
			continue;
		int height_next = solution(node_next, node);
		if (height_next < height_max)
			continue;
		height_max = height[node] + (height_next - height[node]) / 2;
		flag = true;
	}
	if (node_prev < 0)
		return flag;
	return height_max;
}

int main()
{
	FASTIO();

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> height[i];
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		edge[a - 1].emplace_back(b - 1);
		edge[b - 1].emplace_back(a - 1);
	}
	cout << solution(k - 1, -1);
}
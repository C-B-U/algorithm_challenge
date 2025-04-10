#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N; 
	cin >> N;

	int W, H;
	cin >> W >> H;

	vector<pair<int, int>> v;
	v.reserve(N);
	for (int i = 0; i < N; ++i) 
	{
		int x, y; 
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	sort(v.begin(), v.end());

	int ans = 0;
	for (int i = 0; i < N; ++i) 
	{
		if (!binary_search(v.begin(), v.end(), make_pair(v[i].first + W, v[i].second))) 
			continue;

		if (!binary_search(v.begin(), v.end(), make_pair(v[i].first, v[i].second + H))) 
			continue;

		if (!binary_search(v.begin(), v.end(), make_pair(v[i].first + W, v[i].second + H))) 
			continue;

		ans++;
	}

	cout << ans;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// ALJ	CRUO
// ALC	JRUO
// ACL	RJUO
// CAR	LUJO

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N1, N2;
	cin >> N1 >> N2;

	// char : 개미, int : 0(Left), 1(Right)
	vector<pair<char, int>> v;

	string s;
	cin >> s;

	reverse(s.begin(), s.end());

	for (int i = 0; i < s.size(); ++i)
	{
		v.push_back(pair(s[i], 1));
	}

	cin >> s;

	for (int i = 0; i < s.size(); ++i)
	{
		v.push_back(pair(s[i], 0));
	}

	int T;
	cin >> T;

	while (T--)
	{
		for (int i = 0; i < v.size() - 1; ++i)
		{
			// 방향이 다를때만 swap
			if (v[i].second == 1 && v[i + 1].second == 0)
			{
				swap(v[i], v[i + 1]);
				++i;
			}
		}
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i].first;
	}
}
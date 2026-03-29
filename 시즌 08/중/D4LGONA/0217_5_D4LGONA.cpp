#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<pair<int, char>>> v;

int main()
{
	int N;
	int temp;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		v.push_back(vector<pair<int, char>> { });
		for (int j = 0; j < 3; ++j)
		{
			cin >> temp;
			if (i == 0)
			{
				v[i].push_back({temp, j});
				continue;
			}
			int min_v = INT_MAX;
			for (int k = 0; k < v[i - 1].size(); ++k)
			{
				if(v[i - 1][k].second != j)
					min_v = min(v[i - 1][k].first + temp, min_v);
			}
			v[i].push_back({ min_v, j });
		}
	}

	cout << (*min_element(v.back().begin(), v.back().end(), [](const std::pair<int, char>& p1, const std::pair<int, char>& p2) {
		return p1.first < p2.first; })).first << endl;
}
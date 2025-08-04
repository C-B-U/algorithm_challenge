#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	string src, query;
	cin >> src >> query;

	stack<pair<size_t, vector<size_t>>> pos;
	vector<bool> flags(src.size());
	for (size_t index = 0; index < src.size(); ++index)
	{
		char c = src[index];
		if (c == query.front())
			pos.emplace(1, vector<size_t>(1, index));
		else
		{
			if (!pos.empty() && c != query[pos.top().first])
			{
				while (!pos.empty())
					pos.pop();
			}
			if (!pos.empty())
			{
				++pos.top().first;
				pos.top().second.emplace_back(index);
			}
		}
		if (!pos.empty() && pos.top().first >= query.size())
		{
			for (size_t target : pos.top().second)
				flags[target] = true;
			pos.pop();
		}
	}
	string ret;
	for (size_t index = 0; index < src.size(); ++index)
	{
		if (!flags[index])
			ret.push_back(src[index]);
	}
	cout << (ret.empty() ? "FRULA" : ret);
}
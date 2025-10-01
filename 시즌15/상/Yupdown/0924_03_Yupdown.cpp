#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

// ?fanclub?
// s????
// s?ee?

int main()
{
	FASTIO();

	int n;
	string s;
	cin >> n >> s;

	vector<int> st;
	int ret = 0;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] == 's')
			st.emplace_back(1);
		else
		{
			if (!st.empty() && s[i] != "skeep"[st.back()])
				st.clear();
			while (!st.empty() && ++st.back() == 5)
			{
				++ret;
				st.pop_back();
			}
		}
	}
	cout << ret;
}
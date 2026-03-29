#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	int N;
	cin >> N;

	unordered_map<int, int> m;

	for (int i = 0; i < N; ++i)
	{
		int num;
		cin >> num;

		++m[num];
	}

	int ans{};
	for (const auto& [key, value] : m)
	{
		if (key == value)
			ans = max(ans, key);
	}

	if (ans == 0 && m.contains(0))
		ans = -1;

	cout << ans;
};
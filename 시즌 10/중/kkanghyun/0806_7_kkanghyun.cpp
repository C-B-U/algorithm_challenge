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
		int cls;
		cin >> cls;
		++m[cls];
	}

	int ans = 0;
	for (int i = 0; i < N; ++i)
	{
		int cls;
		cin >> cls;
		m[cls] == 0 ? ++ans : --m[cls];
	}

	cout << ans;
}
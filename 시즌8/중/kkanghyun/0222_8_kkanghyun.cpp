#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	vector<int> vecCrane;
	vecCrane.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecCrane[i];
	}
	sort(vecCrane.begin(), vecCrane.end(), greater<int>());

	int M;
	cin >> M;
	vector<int> vecBox;
	vecBox.resize(M);
	for (int i = 0; i < M; ++i)
	{
		cin >> vecBox[i];
	}
	sort(vecBox.begin(), vecBox.end(), greater<int>());

	if (vecBox[0] > vecCrane[0])
	{
		cout << -1;
		return 0;
	}

	int res{};
	while (!vecBox.empty())
	{
		res++;
		for (const int crane : vecCrane)
		{
			for (int i = 0; i < vecBox.size(); ++i)
			{
				if (crane >= vecBox[i])
				{
					vecBox.erase(vecBox.begin() + i);
					break;
				}
			}
		}
	}

	cout << res;
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string S;
	cin >> S;

	int cnt{};
	sort(S.begin(), S.end());

	do
	{
		int size = static_cast<int>(S.size()) - 1;
		bool check{};
		for (int i = 0; i < size; ++i)
		{
			if (S[i] == S[i + 1])
			{
				check = true;
				break;
			}
		}
		if (check == true)
			continue;

		cnt++;

	} while (next_permutation(S.begin(), S.end()));

	cout << cnt;
}
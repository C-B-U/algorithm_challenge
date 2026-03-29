#include <iostream>
#include <string>
#include <climits>

using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;

	int min = INT_MAX;
	int size = static_cast<int>(B.size() - A.size());
	for (int i = 0; i <= size; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < A.size(); ++j)
		{
			if (A[j] != B[j + i])
			{
				cnt++;
			}
		}

		min = std::min(min, cnt);
	}

	cout << min;
}
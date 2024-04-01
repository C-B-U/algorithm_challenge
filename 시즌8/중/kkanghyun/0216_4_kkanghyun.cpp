#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v;
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back(start - end);
	}

	sort(v.begin(), v.end());

	if (N % 2 == 1) {
		cout << 1;
	}
	else 
	{
		cout << v[N / 2] - v[N / 2 - 1] + 1;
	}
}
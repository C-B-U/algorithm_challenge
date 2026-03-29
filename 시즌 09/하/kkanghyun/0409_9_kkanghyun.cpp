#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v;
	v.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	int res{};
	int sum{};
	for (int i = 0; i < N - 1; ++i) {
		if (v[i] < v[i + 1]) {
			sum += v[i + 1] - v[i];
			if (sum > res)
				res = sum;
		}
		else
			sum = 0;
	}

	cout << res;
}
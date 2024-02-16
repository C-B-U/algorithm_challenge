#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long A, B;
	vector<long> v;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> A >> B;
		v.push_back(A - B);
	}
	sort(v.begin(), v.end());

	if (v.size() % 2 != 0)
		cout << "1" << endl;
	else
		cout << v[(v.size() + 1) / 2] - v[(v.size() - 1) / 2] + 1 << endl;
}
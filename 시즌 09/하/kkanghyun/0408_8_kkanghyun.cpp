#include <iostream>
using namespace std;

int main()
{
	int N, T, C, P;
	cin >> N >> T >> C >> P;
	cout << P * C * ((N - 1) / T) << endl;
}
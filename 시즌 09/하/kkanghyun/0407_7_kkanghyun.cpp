#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		string s;
		for (int j = 0; j < M; ++j) {
			char c;
			cin >> c;
			s += c;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	}
}
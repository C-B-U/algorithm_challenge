#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, m;
	cin >> n >> m;

	if (n >= m)
		cout << 0;
	else {
		long long int re = 1;
		for (long long int i = 1; i <= n; i++) {
			re = (re * i) % m;
		}

		cout << re;
	}


	return 0;
}
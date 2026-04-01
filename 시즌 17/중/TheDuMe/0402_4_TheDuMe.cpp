#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> titles(n);
	vector<int> powers(n);

	for (int i = 0; i < n; i++) {
		cin >> titles[i] >> powers[i];
	}

	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;

		int idx = lower_bound(powers.begin(), powers.end(), p) - powers.begin();

		cout << titles[idx] << '\n';
	}

	return 0;
}
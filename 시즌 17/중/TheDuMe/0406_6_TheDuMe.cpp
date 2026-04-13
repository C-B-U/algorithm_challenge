#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int q;
	cin >> q;

	long long a = 1;
	long long d = 1;

	while (q--) {
		int type;
		cin >> type;

		if (type == 0) {
			long long x;
			cin >> x;
			a += x;
		}
		else if (type == 1) {
			long long x;
			cin >> x;
			a *= x;
			d *= x;
		}
		else if (type == 2) {
			long long x;
			cin >> x;
			a += x * d;
		}
		else if (type == 3) {
			cout << a << '\n';
		}
	}

	return 0;
}
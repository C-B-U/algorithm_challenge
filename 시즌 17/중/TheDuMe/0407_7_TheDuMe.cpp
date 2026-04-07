#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s, t;
	cin >> s >> t;

	while (t.length() > s.length()) {
		if (t.back() == 'A') {
			t.pop_back();
		}
		else if (t.back() == 'B') {
			t.pop_back();
			reverse(t.begin(), t.end());
		}
	}

	if (s == t) {
		cout << 1 << '\n';
	}
	else {
		cout << 0 << '\n';
	}

	return 0;
}
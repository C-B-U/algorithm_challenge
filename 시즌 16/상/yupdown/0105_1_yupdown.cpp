#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n == 1)
		cout << 1;
	else {
		// Seidel's Algorithm
		vector<int> table;
		table.emplace_back(1);
		while (--n) {
			reverse(table.begin(), table.end());
			for (size_t i = 1; i < table.size(); ++i)
				table[i] = (table[i] + table[i - 1]) % 1000000;
			table.emplace_back(table.back());
		}
		cout << table.back() * 2 % 1000000;
	}
}
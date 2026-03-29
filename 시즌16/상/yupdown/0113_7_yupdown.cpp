#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;
int table[300][300];
int rsum[300];
int csum[300];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> table[i][j];
			rsum[i] += table[i][j];
			csum[j] += table[i][j];
		}
	}
	int ret = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i == j)
				continue;
			int c1 = -1, max1 = INT_MIN;
			for (int k = 0; k < n; ++k) {
				ret = max(ret, rsum[i] + rsum[j] + csum[k] - (table[i][k] + table[j][k]) * 2);
				ret = max(ret, csum[i] + csum[j] + rsum[k] - (table[k][i] + table[k][j]) * 2);
				int val = csum[k] - table[j][k] - 2 * table[i][k];
				if (val > max1) {
					max1 = val;
					c1 = k;
				}
			}
			int max2 = INT_MIN;
			for (int k = 0; k < n; ++k) {
				int val = csum[k] - table[i][k] - 2 * table[j][k];
				if (k != c1 && val > max2)
					max2 = val;
			}
			ret = max(ret, rsum[i] + rsum[j] + max1 + max2);
		}
	}
	cout << ret;
}
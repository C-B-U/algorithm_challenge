#include <iostream>
#include <algorithm>
using namespace std;



int main(void) {
	int t_n, b_m; // 타워버거, 불고기버거 걸리는 시간
	int T; // 먹을 수 있는 시간
	cin >> t_n >> b_m >> T;
	int r2 = T;
	int r1 = 0;
	for (int i = 0; t_n * i <= T; i++) {
		int k = T - t_n * i;
		int p = k / b_m;
		int q = k % b_m;
		if (q <= r2) {
			q == r2 ? (r1 = max(r1, i + p)) : (r1 = i + p, r2 = q);
		}
	}
	cout << r1 << ' ' << r2;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


int t, b; // 타워버거, 불고기버거 개수
int cola;// 콜라 마신 시간
int result; // 먹은 햄버거 개수

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t_n, b_m; // 타워버거, 불고기버거 걸리는 시간
	int T; // 먹을 수 있는 시간
	int result = 0; // 먹은 햄버거 개수
	cin >> t_n >> b_m >> T;
	int r[1000]; 
	for (t = T / t_n; t > 0; t--) {
		for (b = 0; b <= T/b_m; b++) {
			if ((t_n * t) + (b_m * b) > T) continue;
			cola = T - (t_n * t) + (b * b_m);
			r[t+b] = { cola };
			result = max(result, t + b);
		}
	}
	
	cout << result << " " << r[result] << '\n';
}

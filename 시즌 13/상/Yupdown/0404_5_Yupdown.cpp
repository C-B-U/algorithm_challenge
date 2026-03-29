#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

// 갈톤보드 내에서의 a번째 시작지점의 (x, y)를 구하여 도착지점의 범위를 구할 수 있다.
// y = sqrt((a - 1) * 8 + 1) - 1 / 2
// x = a - (y - 1) * y / 2 - 1

// 구한 범위만큼 도착지점에 b를 범위의 크기로 나누어 더해준다.
// 도착지점의 총 범위는 h + 1이므로 imos 배열을 이용해서 O(1)만에 적용해야한다.
// imos를 누적합하면, 각 도착지점의 기댓값에 대한 배열을 구할 수 있고,
// 이를 한번 더 누적합하면, 구간합을 이용해서 어떤 구간의 기댓값을 O(1)만에 구할 수 있는 배열을 구할 수 있다.

using namespace std;
using int64 = long long;

double imos[1 << 17];

int main()
{
	FASTIO();
	PRECISION(12);

	int h, q, r;
	cin >> h >> q >> r;
	for (int i = 0; i < q; ++i)
	{
		int64 a, b;
		cin >> a >> b;
		int64 hp = static_cast<int64>((sqrt((a - 1) * 8 + 1) - 1) / 2) + 1;
		int64 s = a - (hp - 1) * hp / 2 - 1;
		int64 e = h - hp * (hp + 1) / 2 + a;
		int64 c = e - s + 1;
		double v = static_cast<double>(b) / c;
		imos[s + 1] += v;
		imos[e + 2] -= v;
	}
	for (int i = 1; i <= h + 1; ++i)
		imos[i + 1] += imos[i];
	for (int i = 0; i < h + 1; ++i)
		imos[i + 1] += imos[i];
	for (int i = 0; i < r; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << imos[b] - imos[a - 1] << "\n";
	}
}
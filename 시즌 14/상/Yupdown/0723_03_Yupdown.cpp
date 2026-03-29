#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define PRECISION(n) cout<<fixed,cout.precision(n)

using namespace std;

// 각 짚단의 힘을 계산하는 식 Fi * (Di - Ai + Ci - Bi) / 2 에서 (Di - Ai)와 (Ci - Bi)는 기울기에 따라 선형적인 관계를 가지므로,
// 힘 또한 기울기에 대해 선형 관계임을 알 수 있습니다.
// 그런 이유로, 기울기의 최소와 최대에 대한 경우만 알아내도 정답을 구해낼 수 있습니다.

int table[100000];

int main()
{
	FASTIO();
	PRECISION(6);

	double n, h, s;
	cin >> n >> h >> s;
	for (int i = 0; i < n; ++i)
		cin >> table[i];

	double hpiv = s / n;
	double dmin = min(hpiv, h - hpiv);
	double a = hpiv - dmin;
	double b = hpiv + dmin;

	double reta = 0;
	double retb = 0;
	for (int i = 0; i < n; ++i)
	{
		double tl = static_cast<double>(i) / n;
		double tr = static_cast<double>(i + 1) / n;
		reta += (a * (1 - tl) + b * tl + a * (1 - tr) + b * tr) * table[i] / 2;
		retb += (b * (1 - tl) + a * tl + b * (1 - tr) + a * tr) * table[i] / 2;
	}
	cout << min(reta, retb);
}
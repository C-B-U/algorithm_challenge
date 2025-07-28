#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int main()
{
	FASTIO();

	int n;
	cin >> n;

	// W(294, 553) by http://www.luschny.de/math/rulers/wichmannrulers.html
	int temp[1731]{}, t = 0;
	for (int i = 0; i < 294; ++i)
		temp[t++] = 1;
	temp[t++] = 295;
	for (int i = 0; i < 294; ++i)
		temp[t++] = 589;
	for (int i = 0; i < 553; ++i)
		temp[t++] = 1179;
	for (int i = 0; i < 295; ++i)
		temp[t++] = 590;
	for (int i = 0; i < 294; ++i)
		temp[t++] = 1;
	cout << 1731 << '\n';
	for (int i = 0; i < 1731; ++i)
		cout << temp[i] << ' ';
}
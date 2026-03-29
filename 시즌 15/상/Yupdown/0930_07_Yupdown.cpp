#include <bits/stdc++.h>

using namespace std;

// 분할 정복을 활용한 이분 탐색의 응용 버전: "이진 탐색"
// 처음에는 모든 산에 대한 최대 높이를 구한 후, 2^i 간격으로 탐지기를 사용하며 이전 탐지기의 정보를 최대한 활용한다.
// 탐지 후의 결과값이 모든 산의 최대높이인 경우, 탐지 기준 위치를 그대로 두고,
// 모든 산의 최대 높이 미만인 경우, 탐지 위치를 2^(i-1)로 더해서 변경
// 이후 남은 후보는 최대 2곳이므로 임의의 탐지기를 활용하여 현재 위치가 최대 높이인지 판별
// 탐지 기준 위치를 미리 더한 값으로 둠으로써 배터리 소모를 최소화해야 한다.

int main()
{
	int n, vmax, v, x = 1, base = 2;
	cin >> n;
	cout << "? 1 1 " << n << endl;
	cin >> vmax;
	while (base < n)
	{
		int xp = x + base / 2;
		cout << "? " << xp << " " << base << " " << (n - xp) / base + 1 << endl;
		cin >> v;
		if (v == vmax)
			x = xp;
		base <<= 1;
	}
	if (n > 1)
	{
		cout << "? " << x << " " << n << " 1" << endl;
		cin >> v;
		if (v != vmax)
			x += base / 2;
	}
	cout << "! " << x << endl;
}
#include <bits/stdc++.h>

using namespace std;

// N이 1일경우 - 5면이 노출되는 주사위 하나
// N이 2이상일경우 - 1면이 노출되는 주사위 5n^2-16n+12개, 2면이 노출되는 주사위 8n-12개, 3면이 노출되는 주사위 4개
// 각 n면마다 노출되는 값의 합이 최소가 되도록 후보 중 최솟값을 주사위 수에 곱해주면 된다.

// v1f: 1면이 노출되는 주사위의 값의 합 후보 6개
// v2f: 2면이 노출되는 주사위의 값의 합 후보 12개
// v3f: 3면이 노출되는 주사위의 값의 합 후보 8개

int main()
{
	long long n;
	int a, b, c, d, e, f;
	cin >> n >> a >> b >> c >> d >> e >> f;
	
	int v1f[]{ a, b, c, d, e, f };
	int v2f[]{ a + b, a + c, a + d, a + e, b + c, b + d, b + f, c + e, c + f, d + e, d + f, e + f };
	int v3f[]{ a + b + c, a + b + d, a + c + e, a + d + e, b + c + f, b + d + f, c + e + f, d + e + f };

	if (n > 1)
		cout << (n * n * 5 - n * 16 + 12) * *min_element(cbegin(v1f), cend(v1f)) + (n * 8 - 12) * *min_element(cbegin(v2f), cend(v2f)) + 4 * *min_element(cbegin(v3f), cend(v3f)) << endl;
	else
		cout << a + b + c + d + e + f - *max_element(cbegin(v1f), cend(v1f)) << endl;
}
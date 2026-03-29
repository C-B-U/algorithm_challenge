#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)
#define XORCHAR(a, b) ((((a) - '0') ^ ((b) - '0')) + '0')

using namespace std;

int query(string s, int base, const char segment[4]) {
	static int query_count = 0;
	assert(++query_count <= 3000);
	int i = 0;
	for (; i < 4 && base + i < static_cast<int>(s.size()); ++i)
		s[base + i] = XORCHAR(segment[i], s[base + i]);
	cout << "? " << s << endl;
	int ret;
	cin >> ret;
	for (; i < 4; ++i)
		ret += segment[i] == '0';
	return ret;
}

int main()
{
	FASTIO();

	// 길이가 4인 이진 수열로 나누어서 구간별로 쿼리를 수행한 후 차이를 구한다.
	// 이진 수열당 쿼리 수행 기댓값은 2.875회. 즉 길이가 4000인 이진 수열에 대해서 평균적으로 2875회의 쿼리를 수행한다.
	// 01010101... 과 같은 이진 수열은 Edge Case이므로 길이가 같은 임의의 이진 수열과 XOR 연산을 적용하여 해결한다.

	srand(reinterpret_cast<long long>("2026 씨부엉 화이팅"));

	int n;
	cin >> n;

	string ret, s;
	for (int i = 0; i < n; ++i)
		s.push_back(rand() % 2 + '0');
	int pivot = query(s, 0, "0000");
	for (int i = 0; i < n; i += 4) {
		if (n > 4 && i + 4 > n) {
			i -= 4 - (n - i);
			ret = ret.substr(0, i);
		}
		int d1, d2, d3, d4;
		d1 = query(s, i, "1111") - pivot;
		switch (d1) {
		case -4:
			ret.append("0000");
			break;
		case -2:
			d2 = query(s, i, "1100") - pivot;
			switch (d2) {
			case -2:
				d4 = query(s, i, "0010") - pivot;
				ret.append(d4 == 1 ? "0010" : "0001");
				break;
			case 0:
				d3 = query(s, i, "1000") - pivot;
				ret.append(d3 == 1 ? "1000" : "0100");
				break;
			}
			break;
		case 0:
			d2 = query(s, i, "1100") - pivot;
			switch (d2) {
			case -2:
				ret.append("0011");
				break;
			case 0:
				d3 = query(s, i, "1000") - pivot;
				d4 = query(s, i, "0010") - pivot;
				if (d3 == 1)
					ret.append(d4 == 1 ? "1010" : "1001");
				else
					ret.append(d4 == 1 ? "0110" : "0101");
				break;
			case 2:
				ret.append("1100");
				break;
			}
			break;
		case 2:
			d2 = query(s, i, "1100") - pivot;
			switch (d2) {
			case 0:
				d3 = query(s, i, "1000") - pivot;
				ret.append(d3 == 1 ? "1011" : "0111");
				break;
			case 2:
				d4 = query(s, i, "0010") - pivot;
				ret.append(d4 == 1 ? "1110" : "1101");
				break;
			}
			break;
		case 4:
			ret.append("1111");
			break;
		}
	}
	for (int i = 0; i < n; ++i)
		ret[i] = XORCHAR(ret[i], s[i]);
	cout << "! " << ret.substr(0, n) << endl;
}
#include<iostream>
#include<vector>
#include<string>

typedef struct A {
	std::string s;
	int power;

	friend std::istream& operator>>(std::istream &is, A &a) {
		is >> a.s >> a.power;
		return is;
	}
}A;

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int N, M,temp;
	std::cin >> N >> M;
	std::vector<A> v(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i];

		// 동일 칭호 중복 처리
		if (i != 0 && v[i].power == v[i - 1].power) {v[i].s=v[i-1].s; }
	}
	while (M--) {
		int minIdx = 0, maxIdx = N - 1, curIdx = (minIdx + maxIdx) / 2,t=0;
		std::cin >> temp;
		while (curIdx!=t) {
			t = curIdx;
			(temp <= v[curIdx].power ? maxIdx : minIdx) = curIdx;
			curIdx = (minIdx + maxIdx) / 2;
		}
		// 마지막 경우의 수 확인
		std::cout << (temp>v[curIdx].power?v[curIdx+1].s:v[curIdx].s) << '\n';
	}
}

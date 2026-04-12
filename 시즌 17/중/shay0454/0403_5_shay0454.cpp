#include<iostream>
#include<vector>
#include<algorithm>

typedef struct A {
	int r, c;
	int num, ans;
};
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	int H, N;
	std::cin >> H >> N;
	std::vector<A> v(N);
	for (int i = 0; i < N; i++) {
		std::cin >> v[i].r >> v[i].c;
		v[i].num = i;
	}
	std::sort(v.begin(), v.end(), [](A a, A b) {return a.c > b.c; });
	for (auto& x : v) {
		x.ans = N--;
	}
	std::sort(v.begin(), v.end(), [](A a, A b) {return a.num < b.num; });
	std::cout << "YES\n";
	for (auto x : v) {
		std::cout << x.ans << ' ';
	}
}

#include<iostream>

int main() {
	long long N, M, ans=1;
	std::cin >> N >> M;
	std::cout << [&N,M,&ans]() {
		if (N > M) return static_cast<long long>(0);
		while (N--) {
			ans *= (N + 1);
			if ((ans %= M) == 0)break;
		}
		return ans;
		}();
}

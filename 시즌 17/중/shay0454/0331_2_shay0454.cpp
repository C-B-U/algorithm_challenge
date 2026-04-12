#include<iostream>
// 이게 뭔 문제여....
int main() {
	int T,N,M,a,b;
	std::cin >> T;
	while (T--) {
		std::cin >> N >> M;
		while (M--) {
			std::cin >> a >> b;
		}
		std::cout << N-1<<'\n';
	}
}

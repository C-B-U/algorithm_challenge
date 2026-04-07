#include<iostream>
#include<string>
#include<queue>
#include<algorithm>

int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0);
	std::string S, T;
	std::cin >> S >> T;
	std::queue<std::string> q;

	// 1,2 번에 따른 결과인지는 결과의 마지막 문자로 분류가능
	// 역으로 계산하여 크기가 같을 떄 같은지를 확인
	while (T.size() != S.size()) {
		if (T.back() == 'A') { T = T.substr(0, T.size() - 1); }
		else { T = T.substr(0, T.size() - 1); std::reverse(T.begin(), T.end()); }
	}
	std::cout << (T == S ? 1 : 0);
}

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

int main() {
	int N, ans = 0;
	std::string s;
	std::vector<int> weight(26);
	std::cin >> N;
	for (int i = 0; i < N; i++) {
		std::cin >> s;
		for (int i = s.size() - 1, w = 1; i >= 0; w *= 10, i--) {
			weight[s[i]-'A'] += w;
		}
	}
	std::sort(weight.begin(), weight.end(), std::greater<int>());
	for (int i = 0; i < 10; i++) {
		ans += weight[i] * (9-i);
	}
	std::cout << ans;
}

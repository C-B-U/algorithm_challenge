#include<iostream>
#include<vector>


int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	int N, K, X,ans=-1;
	std::cin >> N >> K >> X;
	std::vector<int> list(N+1);
	std::vector<int> sum(N+1);
	for (int i = 1; i <=N; i++) {
		std::cin >> list[i];
		sum[i] = sum[i - 1] + list[i];
	}
	for (int i = 1,cnt=1; i <= N; i++,cnt=1) {
		int startIdx = i, endIdx = N, curIdx = (startIdx + endIdx) / 2;
		while (startIdx+1<endIdx) {
			curIdx = (startIdx + endIdx) / 2;
			(X * sum[i - 1] + sum[N] - sum[curIdx] >= K ? startIdx : endIdx) = curIdx;
		}
		if (curIdx+1<=N&& X * sum[i - 1] + sum[N] - sum[curIdx + 1] >= K)curIdx++;
		if (X * sum[i - 1] + sum[N] - sum[curIdx] < K)continue;
		ans = std::max(ans, curIdx - i + 1);
	}
	std::cout << ans;
}

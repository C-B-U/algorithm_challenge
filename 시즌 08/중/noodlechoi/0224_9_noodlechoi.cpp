#include <iostream>
#include <vector>

// 트리
/*
트리가 주어졌을 때, 노드 하나를 지울 것이다. 그 때, 남은 트리에서 리프 노드의 개수를 구하는 프로그램을 작성하시오. 노드를 지우면 그 노드와 노드의 모든 자손이 트리에서 제거된다.
*/

using namespace std;

vector<int> nodes[51];
int k;

int dfs(const int& node, int& leaf) {
	if (node == k) return -1;
	if (!nodes[node].size()) {
		leaf++;
		return 0;
	}
	for (int i = 0; i < nodes[node].size(); i++) {
		int tmp = dfs(nodes[node][i], leaf);
		if (tmp == -1 && nodes[node].size() == 1)
			leaf++;
	}

	return 0;
}

int solution(const int& root) {
	int leaf = 0;

	dfs(root, leaf);
	return leaf;
}

int main()
{
	int N;
	cin >> N;

	// 입력
	int root = 0;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		if (n == -1)
			root = i;
		else
			nodes[n].push_back(i);
	}

	cin >> k;
	cout << solution(root) << endl;
}
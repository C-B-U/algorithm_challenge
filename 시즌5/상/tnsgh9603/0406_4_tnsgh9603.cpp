#include <bits/stdc++.h>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int in_order[100'001], post_order[100'001], position[100'001];
void solve(int is, int ie, int ps, int pe) {
	// is -> inorder_start,  ie -> inorder_end
	// ps -> position_start, pe -> position_end
	if (is > ie || ps > pe) {
		return;
	}
	int root = post_order[pe];
	cout << root << ' ';  // 루트 노드 출력
	int ir = position[root]; // in_order 배열 안 ir위치에 root값이 들어있다.
	int left = ir - is;
	solve(is, ir - 1, ps, ps + left - 1); //왼쪽 서브트리 탐색
	solve(ir + 1, ie, ps + left, pe - 1); // 오른쪽 서브트리 탐색
}
int main() {
    fastio;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in_order[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> post_order[i];
	}
	for (int i = 0; i < n; i++) {
		position[in_order[i]] = i; // in_order에서 값 i의 위치를 저장하는 position 배열
	}
	solve(0, n - 1, 0, n - 1);
	return 0;
}

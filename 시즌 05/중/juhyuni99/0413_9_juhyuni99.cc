#include<iostream>
using namespace std;

int num;
int lotto[14];
int ans[6];
void dfs(int start, int depth) {

	//종료조건
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	//재귀: 재귀가 return 되면 다시 다음문자에 대해 dfs
	for (int i = start; i < num; i++) {
		ans[depth] = lotto[i];
		dfs(i + 1, depth + 1);
	}

}
int main() {

	while (cin >> num && num) {
		for (int i = 0; i < num; i++) {
			cin >> lotto[i];
		}
		dfs(0, 0);
		cout << endl;
	}
	return 0;
}

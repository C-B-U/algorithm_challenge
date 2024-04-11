#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	
	// 보드를 생성하고 칸마다 지시사항 저장
	vector<int> board;
	board.reserve(N);
	for (int i = 0; i < N; ++i) {
		int X;
		cin >> X;
		board.push_back(X);
	}

	int pos{};	// 0 : 1번 칸
	for (int i = 0; i < M; ++i) {
		int j;
		cin >> j;
		pos += j;
		// N번 칸 도착 또는 그 이상이라면 던진 주사위 횟수 저장하고 break
		if (pos >= N - 1) {
			N = i + 1;
			break;
		}

		pos += board[pos];

		// N번 칸 도착 또는 그 이상이라면 던진 주사위 횟수 저장하고 break
		if (pos >= N - 1) {
			N = i + 1;
			break;
		}
	}

	cout << N << endl;
}
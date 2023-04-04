#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> card;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int Card;
		cin >> Card;
		card.push_back(Card);
	}
	sort(card.begin(), card.end()); //오름차순 정렬

	cin >> M;
	//이진 탐색
	//upper_bound : 찾고자 하는 값의 다음 값이 최초로 나타나는 위치
	//lower_bound : 찾고자 하는 값 이상이 처음 나타나는 위치
	for (int i = 0; i < M; i++) {
		int Card1;
		cin >> Card1;
		cout << upper_bound(card.begin(), card.end(), Card1) - lower_bound(card.begin(), card.end(), Card1) << ' ';
	}
}

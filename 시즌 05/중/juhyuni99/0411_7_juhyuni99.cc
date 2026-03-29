#include <iostream>
#include <map>

using namespace std;

long int N, T, num,ans,idx;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N; //땅의 개수

	for (int a = 0; a < N; a++) {

		map <long int, int> arr; // 각 군대번호에 대한 병사 수
        
		cin >> T; // 땅의 병사 수
		for (int b = 0; b < T; b++) {
			cin >> num;
			//map 함수인 cnt에서 ti를 key로 하는 원소의 값을 1 증가
			//ti를 key로 하는 원소가 없으면 새로운 원소를 추가하고 값을 1로 초기화
			if (++arr[num] > T/2) { 
				ans = arr[num];// 가장 많은 병사를 보유한 군대의 병사수
				idx = num;// 군대 번호
			}

		}

		if (ans > T / 2) {
			cout << idx << "\n";
		}

		else {
			cout << "SYJKGW"<<"\n";
		}
		ans = 0;
		idx = 0;
		arr.clear();

	}
}

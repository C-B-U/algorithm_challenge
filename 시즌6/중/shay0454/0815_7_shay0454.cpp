#include<iostream>
using namespace std;
bool truth_table[2000];//범위는 1000이지만 아래의 작업을 위해 +1000(L의 최대값)
int main() {
	int N, L, num, count_ = 0; fill_n(truth_table, 1000, true);//영역 내의 모든 값을 true로 
	cin >> N >> L;//N, L 값 입력
	for (int i = 0; i < N; i++) { cin >> num; truth_table[num - 1] = false; }//물이 새는 위치 입력 후, 위치를 truth_table에 false로 초기화 (카운팅 정렬)
	for (int i = 0; i < 1000; i++) {
		if (truth_table[i] == false) { fill_n(truth_table + i, L,true); count_++;	 }//만약 false를 보면 테이프의 영역까지 모두 true로 변경, count_++
	}//앞 번호 제외해서 붙인다 해도 앞 번호에 다시 붙여야하기에 앞에서 테이프의 영역까지 붙인다. 이러면 최소한의 개수로 붙일 수 있음
	cout << count_;
	return 0;
}

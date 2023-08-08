#include <iostream>
using namespace std;

int main() {
	int injury; // 다친 손가락 번호
	long long i_count, count = 0; // 사용 가능 횟수. 셀 수 있는 최대값
	bool is_up;

	cin >> injury;
	cin >> i_count;

	if (injury == 1 || injury == 5) i_count *= 2; // 가장자리 손가락은 중간의 손가락 보다 2배 적게 사용하므로 사용횟수가능 횟수 2배로 조정
	is_up = i_count % 2 == 0; // 손가락이 일어나는 턴인지 확인
	
	count = 4 * (i_count + 1); // 다음 턴의 최대값으로 이동

	count -= (is_up) ? (5 - injury) : (injury - 1); // 만약 상승하는 턴이면 5번째 손가락이 최대값으므로 다친 손가락 번호를 빼서 뒤로 한칸 이동, 아니라면 1번째 손가락이 최대값이므로 다친 손가락 번호에 빼줘서 뒤로 한칸 이동

	cout << count;
}

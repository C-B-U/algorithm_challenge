#include<iostream>
using namespace std;
long long X, Y, W, S;
long long checku() {
	long long now = 0, sum = 0;
	if (2 * W < S) return (X + Y) * W;	//대각선 이동(+1,+1)보다 가로,세로 이동((+1,0),(0,+1))이 더 최단인 경우
	now=((X > Y) ? Y : X);			// X, Y 중 작은 거 초기화
	sum += S * now;				// 더 작은 Q로 (Q,Q)까지 대각선 이동 (0,0)>>(Q,Q) 대각선과 가로_세로 이동 비교는 이미 함
	now = (X - now) + (Y - now);		// 남은 거 찾기
	sum += (now / 2) * ((2 * W > 2*S) ? 2 * S : 2 * W) + ((now % 2 == 0) ? 0 : W);
	return sum;				// 같은 축으로 2칸 씩 이동할때의 효율 계산, 1칸이 남았다면 추가. 마지막으로 리턴
}
int main() {
	cin >> X >> Y >> W >> S;
	cout<<checku();				//리턴 값 출력
	return 0;
}

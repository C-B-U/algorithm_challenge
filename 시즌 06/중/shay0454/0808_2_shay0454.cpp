#include<iostream>
using namespace std;
int main() {
	long long finger, sum, useLimit;
	cin >> finger >> useLimit;
	sum = 8 * (useLimit / ((finger != 1 && finger != 5)?2:1))+ finger - 1;
	sum += ((finger != 1 && finger != 5&&useLimit%2)?10 - 2 * finger:0);
	cout << sum;
	return 0;
}
// 각각의 손가락은 횟수에 대해 아래와 같은 결과가 나옴
// 1 : 1, 9 , 17, .... >> 1, 1*8+1, 2*8+1, ....
// 2 : 2, 8 ,10, 16, .... >> 2, 8, 8+2, 8+8, ....
// 3 : 3, 7, 11, 15, .... >> 3, 7 ,8+3, 8+7, ....
// 4 : 4, 6, 12, 14, .... >> 4, 6, 8+4, 8+6, ....
// 5 : 5, 13, 21, .... >> 5, 1*8+5, 2*8+5, ....
// 이때 1과 5를 제외한 다른 수들은 두 번 후 ++8 (8진법(?))을 한 후, 
// 손가락을 finger, 사용제한을 useLimit라 칭하자
// 다음 번째의 수가 되고, (2, 8),(3, 7),(4, 6) 같이 첫 수는 finger, 다음 수는 10-finger가 된 후 ++8이 된다
// finger가 1 or 5이면 8*useLimit+finger이 finger의 useLimit+1 번째의 수가 나온다 (이를 위해 -1). 
// finger갸 !=1 and !=5이면 8*(useLimit/2)를 먼저 선언하면 위 결과처럼 +8의 횟수, 그리고 useLimit가 짝이냐 홀이냐에 따라 더해야한다.
// 짝이면 +finger 하면 finger의 useLimit+1 번째의 수 (이를 위해 -1), 홀이면 +(10-finger) 하면 finger의 useLimit+1 번째의 수가 나온다 (이를 위해 -1).
// 위는 finger == 1 or 5의 조건에 따라 나누고 finger-1를 미리 해놓았으며, finger !=1 and !=5 and useLimit%2==1이면 22줄의 결과를 위해 sum+=10-2*finger를 한다.
// 솔직히 이렇게 단축하고 많은 주석을 단게 처음이다.

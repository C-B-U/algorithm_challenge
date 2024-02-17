#include<iostream>
using namespace std;
int n, list[2][3],red,green,blue;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> list[1][0] >> list[1][1] >> list[1][2];
		red = list[1][0] + ((list[0][1] < list[0][2]) ? list[0][1] : list[0][2]);
		green = list[1][1] + ((list[0][0] < list[0][2]) ? list[0][0] : list[0][2]);
		blue = list[1][2] + ((list[0][0] < list[0][1]) ? list[0][0] : list[0][1]);
		list[0][0] = red, list[0][1] = green, list[0][2] = blue;
	}
	cout << min(red, min(green, blue));
	return 0;
}

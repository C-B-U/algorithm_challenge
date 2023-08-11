#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<vector<int>>> v;
void print_compression(int num, int y = 0,int x=0) {
	if (v[num][y][x] == (int)pow((int)pow(2,num),2))cout << 1;
	else if (v[num][y][x] == 0)cout << 0;
	else {
		cout << '(';
		print_compression(num - 1, 2 * y, 2 * x);
		print_compression(num - 1, 2 * y, 2 * x + 1);
		print_compression(num - 1, 2 * y + 1, 2 * x);
		print_compression(num - 1, 2 * y + 1, 2 * x + 1);
		cout << ')';
	}
}
int main() {
	char c; int n, num; cin >> n; num = n;
	for (int i = 0; i <= (int)log2(n); i++,num/=2) {
		v.push_back(vector<vector<int>>());
		for (int j = 0; j < num; j++) {
			v[i].push_back(vector<int>());
			for (int k = 0; k < num; k++){
				if (i == 0) {
					cin >> c;
					v[i][j].push_back(c - '0');
				}
				else v[i][j].push_back(v[i - 1][2 * j][2 * k] + v[i - 1][2 * j + 1][2 * k] + v[i - 1][2 * j][2 * k + 1] + v[i - 1][2 * j + 1][2 * k + 1]);
			}
		}
	}
	print_compression((int)log2(n));
	return 0;
}

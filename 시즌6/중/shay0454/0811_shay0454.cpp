#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
vector<vector<vector<int>>> v;
void print_compression(int num, int y = 0,int x=0) {           // 압축 결과 출력 함수
	if (v[num][y][x] == (int)pow((int)pow(2,num),2))cout << 1;   // 해당 칸이 압축 전 칸의 총합과 같으면 cout<<1
	else if (v[num][y][x] == 0)cout << 0;                        // 해당 칸의 압축이 0이면 cout<<0
	else {
		cout << '(';                                               // 그 외에는 압축을 한 번 풀어 2x2 사이즈로 분리 위 조건 확인
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
		v.push_back(vector<vector<int>>());                        // 2차원 vector를 넣기위한 공간 생성
		for (int j = 0; j < num; j++) { 
			v[i].push_back(vector<int>());                           // 1차원 vector를 넣기위한 공간 생성
			for (int k = 0; k < num; k++){
				if (i == 0) {                                          // 코드 줄이려고 처음일 때 받기
					cin >> c;                                            // 한 숫자씩 받기 위한 char input
					v[i][j].push_back(c - '0');                          // 수로 만들기 위해 -'0'
				}                                                      // 처음 외에는 해당 칸의 2x2 압축(총합)을 삽입
				else v[i][j].push_back(v[i - 1][2 * j][2 * k] + v[i - 1][2 * j + 1][2 * k] + v[i - 1][2 * j][2 * k + 1] + v[i - 1][2 * j + 1][2 * k + 1]);
			}
		}
	}
	print_compression(log2(n));                                  // 압축 결과 출력
	return 0;
}

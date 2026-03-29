#include<iostream>
using namespace std;
int answer; string s; bool tf[10];
void back_track(char c=' ', int count_=0) {
	char a; a = c;
	for (int i = 0; i < s.size(); i++,c=a) {
		if (!tf[i] && c != s[i]) {
			c = s[i]; tf[i] = true; 
			if (count_ == s.size()-1)answer++;
			else back_track(c, count_ + 1); 
			tf[i] = false;
		}
	}
}
int count_same_alphabet(char c) {
	int cnt = 0;
	for (int i = 0; i < s.size(); i++)if (s[i] == c)cnt++;
	return cnt;
}
int permutation(int i) {
	int x = 1;
	while (i--) {x *= i+1;}
	return x;
}
int main() {// 이게 왜 시간초과가 안나지
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	back_track();
	for (int i = 0, x; i < 26; i++) {
		x = count_same_alphabet('a' + i);
		if(x>1)answer/=permutation(x); }
	cout << answer;
}

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;
bool alphabet[26] = { false, };
int N, point[30],num;
string s[30], lower_s, sub_s;
vector<string> v, sub_v;
bool find_for_option_1(string s,int count_) {
	for (auto a = v.begin(); a != v.end(); a++)
		if (*a == s) return false;
	if (!alphabet[s[0] - 'a']) {
		alphabet[s[0] - 'a'] = true;
		point[num] = count_;
		v.push_back(s);
		return true;
	}
	return false;
}
bool find_for_option(string lower_s,string sub_s) {
	int count_ = 0;
	istringstream cin_s(lower_s);
	while (getline(cin_s, sub_s, ' ')) {
		if (find_for_option_1(sub_s, count_)) return true;
		else { count_ += sub_s.length() + 1; }
	}
	for (int i = 0; i < s[num].length(); i++) {
		if (!alphabet[lower_s[i] - 'a'] && lower_s[i] != ' ') { 
			alphabet[lower_s[i] - 'a'] = true;
			point[num] = i;
			return true;
		}
	}
	point[num] = -1;
	return false;
}
int main() {
	cin >> N; getchar();
	for (num = 0; num < N; num++) {
		getline(cin, s[num]);
		lower_s = s[num];
		for (int j = 0; j < lower_s.size(); j++)if (lower_s[j] >= 65 && lower_s[j] <= 90)lower_s[j] += 32;
		find_for_option(lower_s, sub_s);
		for (int i = 0; i < s[num].length(); i++) {
			if (i == point[num])cout << '[' << s[num][i] << ']';
			else cout << s[num][i];
		} cout << '\n';
	}
	return 0;
}

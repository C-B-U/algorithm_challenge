#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string s; 
	cin >> s;

	string res = s;
	for (int i = 0; i < s.size() - 2; ++i) {
		for (int j = i + 1; j < s.size() - 1; ++j) {
			string tmp = s;

			reverse(tmp.begin(), tmp.begin() + i + 1);
			reverse(tmp.begin() + i + 1, tmp.begin() + j + 1);
			reverse(tmp.begin() + j + 1, tmp.end());

			res = min(tmp, res);
		}
	}

	cout << res << endl;
}
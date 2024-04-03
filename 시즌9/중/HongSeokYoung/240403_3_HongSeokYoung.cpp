#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	int n;
	int cycle;
	int count = 0;
	string s;
	string standard_list = "";
	string compare_list = "";
	string result[110];

	cin >> n;

	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;

		standard_list += c;
		compare_list += (c + 1) % 4 + 1 + '0';
	}
	reverse(compare_list.begin(), compare_list.end());

	cin >> cycle;

	while (cycle--) {
		s = "";
		for (int i = 0; i < n; ++i) {
			char c;
			cin >> c;

			s += c;
		}

		string temp = s;

		for (int i = 0; i < n; ++i) {
			if (temp == standard_list || temp == compare_list) {
				result[count] = s;
				++count;
				break;
			}
			temp = temp.substr(1, temp.length()) + temp[0];
		}
	}

	cout << count << endl;

	for (int i = 0; i < count; ++i) {
		for (int j = 0; j < standard_list.length(); ++j) {
			cout << result[i][j];
			if (j < standard_list.length() - 1) {
				cout << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
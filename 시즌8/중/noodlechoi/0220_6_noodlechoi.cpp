#include <iostream>
#include <algorithm>

// 행운의 문자열
/*
* 첫째 줄에 문자열 S가 주어진다. S의 길이는 최대 10이고, 알파벳 소문자로만 이루어져 있다.
* 첫째 줄에 위치를 재배치해서 얻은 서로 다른 행운의 문자열의 개수를 출력한다.
*/

using namespace std;

int alphabet[27];
int result;

void solution(int idx, string tmp, const string& str)
{
	if (idx == str.size()) {
		result++;
		return;
	}

	for (int i = 0; i < 26; ++i) {
		if (alphabet[i] == 0) continue;	// 입력 받지 않은 알파벳으면
		if (tmp != "" && tmp[tmp.size() - 1] == static_cast<char>('a' + i)) continue; // 이전 것과 같으면
		alphabet[i]--;
		solution(idx + 1, tmp + static_cast<char>('a' + i), str);
		alphabet[i]++;
	}
}


int main()
{
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); ++i) {
		alphabet[str[i] - 'a']++;	// 소문자만 입력
	}

	solution(0, "", str);

	cout << result << endl;
}
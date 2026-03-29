#include <iostream>
// 문자열
/*
두 문자열 A와 B가 주어진다. 이때, A의 길이는 B의 길이보다 작거나 같다. 이제 A의 길이가 B의 길이와 같아질 때 까지 다음과 같은 연산을 할 수 있다.

A의 앞에 아무 알파벳이나 추가한다.
A의 뒤에 아무 알파벳이나 추가한다.
이때, A와 B의 길이가 같으면서, A와 B의 차이를 최소로 하는 프로그램을 작성하시오.
*/

using namespace std;

int GetDiff(const string& x, const string& y)
{
	int mini = 100; // A와 B의 길이는 최대 50
	for (int i = 0; i < y.size(); ++i) {
		if (i + x.size() > y.size()) break;

		int diff = 0;
		for (int j = 0; j < x.size(); ++j) {
			if (x[j] != y[i + j]) diff++;
		}
		mini = min(diff, mini);
	}

	return mini;
}

int main()
{
	string X, Y;
	cin >> X >> Y;
	cout << GetDiff(X, Y) << endl;
}
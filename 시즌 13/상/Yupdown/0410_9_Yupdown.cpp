#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

// f(x) = ax + b 라고 할 때, f(x_0) = x_1, f(x_1) = x_2 를 만족하고자 하면 a와 b를 결정할 수 있다.
// 
// x가 하나만 주어졌을 경우 f(x)를 정의할 수 없다. (A 출력)
// x가 두개만 주어졌을 경우 x_0 = x_1 의 경우를 제외하고 f(x)를 정의할 수 없다. (A 출력)
// 
// x_0 = x_1 일 때는 x_i = x_0 for any i >= 0 이어야 규칙이 성립한다.
// 하나라도 성립이 되지 않으면 B를 출력하고, 모두 성립할 경우 x_0을 출력한다.
// 
// x_0 = x_1 이 아닐 때는, a = (x_2 - x_1) / (x_1 - x_0), b = x_1 - x_0 * a 로 정의할 수 있다.
// a 가 정수가 아닐 경우 문제의 조건에 부합하지 않으므로 B를 출력해야 한다.
// 
// a와 b가 결정된 f(x)를 가지고 f(x_i) = x_(i+1) for any i >= 2가 성립하는지 확인하자.
// 하나라도 성립이 되지 않으면 B를 출력하고, 모두 성립할 경우 규칙을 만족하므로 f(x_(n-1))를 출력한다.

using namespace std;
int table[50];

int main()
{
	FASTIO();

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> table[i];
	if (n == 1)
		cout << "A";
	else if (n == 2)
	{
		if (table[0] == table[1])
			cout << table[0];
		else
			cout << "A";
	}
	else
	{
		int x0 = table[0];
		int x1 = table[1];
		int x2 = table[2];
		if (x0 == x1)
		{
			if (x1 != x2)
				cout << "B";
			else if (count(table, table + n, table[0]) == n)
				cout << table[0];
			else
				cout << "B";
		}
		else if ((x2 - x1) % (x1 - x0))
			cout << "B";
		else
		{
			int a = (x2 - x1) / (x1 - x0);
			int b = x1 - x0 * a;
			bool flag = true;
			for (int i = 2; i < n - 1; ++i)
				flag &= table[i + 1] == table[i] * a + b;
			if (flag)
				cout << table[n - 1] * a + b;
			else
				cout << "B";
		}
	}
}
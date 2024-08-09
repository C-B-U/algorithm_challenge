#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	stack<int> cont;

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin.ignore();

		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			cont.push(num);
			continue;
		}

		switch (s.front())
		{
		case 'p':	// pop
		{
			int num = cont.empty() ? -1 : cont.top();
			if (num != -1)
				cont.pop();
			cout << num << '\n';
		}
			break;
		case 's':	// size
			cout << cont.size() << '\n';
			break;
		case 'e':	// empty
		{
			int num = cont.empty() ? 1 : 0;
			cout << num << '\n';
		}
			break;
		case 't':	// top
		{
			int num = cont.empty() ? -1 : cont.top();
			cout << num << '\n';
		}
			break;
		}
	}
}
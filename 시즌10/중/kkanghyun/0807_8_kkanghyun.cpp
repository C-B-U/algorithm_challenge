#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>
using namespace std;

struct Memo
{
	int day;
	int cost;
};

int main()
{
	int N;
	cin >> N;

	unordered_map<string, Memo> m;
	array<bool, 10 * 7> days{};	// weak �� �ִ� 10
	string name;
	int weak, day, cost;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> weak >> day >> cost;
		day += weak * 7 - 7;	// weak �� 1���� ����

		m.insert(make_pair(name, Memo(day, cost)));
	}

	int cash;
	for (int i = 0; i < N; ++i)
	{
		cin >> name >> cash;
		if (m[name].cost > cash)
		{
			m.erase(name);
		}
	}

	for (const auto& [key, value] : m)
	{
		days[value.day] = true;
	}

	int cnt{};
	int mx{};
	for (int i = 0; i < days.size(); ++i)
	{
		if (days[i])
			++cnt;
		else
			cnt = 0;

		mx = max(cnt, mx);	// ������ ��¥���� ����� �ݿ��ϱ� ���� ���⿡�� �˻�
	}

	cout << mx;
}
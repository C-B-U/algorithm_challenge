#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : 마친학기
	// A : 전공개수
	// B : 이수학점
	int N, A, B;
	cin >> N >> A >> B;
	int semester = 8 - N;		// 남은 학기
	int majorGrade = 66 - A;	// 남은 전공학점
	int totalGrade = 130 - B;	// 남은 총 학점

	int a, b;
	for (int i = 0; i < 10; ++i)
	{
		cin >> a >> b;

		if (i >= semester)
			continue;

		majorGrade -= a * 3;

		int grade = (a + b) * 3;
		if (grade > 18)
			grade = 18;

		totalGrade -= grade;
	}

	if (majorGrade > 0 || totalGrade > 0)
		cout << "Nae ga wae";
	else
		cout << "Nice";
}
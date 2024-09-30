#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	// N : ��ģ�б�
	// A : ��������
	// B : �̼�����
	int N, A, B;
	cin >> N >> A >> B;
	int semester = 8 - N;		// ���� �б�
	int majorGrade = 66 - A;	// ���� ��������
	int totalGrade = 130 - B;	// ���� �� ����

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
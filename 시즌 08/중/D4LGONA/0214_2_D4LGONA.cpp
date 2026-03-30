#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int cnt = 0;

	if (A.length() == B.length())
	{
		for (int i = 0; i < A.length(); ++i)
		{
			if (A[i] != B[i]) cnt++;
		}
		cout << cnt << endl;
	}
	else
	{
		int cnt2 = 0;
		cnt = 2147483647;
		int length = B.length() - A.length();

		for (int j = 0; j < A.length(); ++j)
		{
			if (A[j] != B[j])
				cnt2++;
		}
		if (cnt2 < cnt) cnt = cnt2;
		cnt2 = 0;

		for (int i = 0; i < length ; ++i)
		{
			A.insert(i, 1, B[i]);
			for (int j = 0; j < A.length(); ++j)
			{
				if (A[j] != B[j]) 
					cnt2++;
			}
			if (cnt2 < cnt) cnt = cnt2;
			cnt2 = 0;
		}

		cout << cnt << endl;
	}

}
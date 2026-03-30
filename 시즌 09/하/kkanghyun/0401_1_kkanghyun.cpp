#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;
	
	for (int i = 1; i <= L; ++i) {
		A -= C;
		B -= D;

		if (A <= 0 && B <= 0) {
			cout << L - i << endl;
			break;
		}
	}
}
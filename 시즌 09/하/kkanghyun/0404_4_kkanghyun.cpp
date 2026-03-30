#include <iostream>
using namespace std;

int main()
{
	while (true) {
		int A;
		cin >> A;
		if (cin.eof() == true)
			break;

		if (A % 6 == 0)
			cout << "Y" << endl;
		else
			cout << "N" << endl;
	}
}
#include <iostream>

using namespace std;

int main() {

	int test = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	unsigned int nations = 0;
	unsigned int method = 0;
	unsigned int m1 = 0;
	unsigned int m2 = 0;



	cin >> test;

	int* plane = new int[test];

	for (cnt1 = 0; cnt1 < test; cnt1++) {

		cin >> nations >> method;

		for (cnt2 = 0; cnt2 < method; cnt2++) {

			cin >> m1 >> m2 ;

		}
		
		*(plane + cnt1) = nations - 1;

	}

	for (cnt1 = 0; cnt1 < test; cnt1++) {

		cout << *(plane + cnt1) << endl;
	}

	delete(plane);


	return 0;
}
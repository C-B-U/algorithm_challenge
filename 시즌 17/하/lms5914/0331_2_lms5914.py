#include <iostream>
using namespace std;

int main() {
    int num;
    int max_val = 0;
    while (cin >> num) {
        if (num > max_val) {max_val = num; }
        char c = cin.get();
        if (c == '\n') {break;}
    }
    cout << max_val << endl;
    return 0;
}

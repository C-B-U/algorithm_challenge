#include <iostream>
#include <string>

using namespace std;

int main() {

    string S;
    cin >> S;

    int hasA = 0, hasB = 0, hasC = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == 'A') hasA = 1;
        if (S[i] == 'B') hasB = 1;
        if (S[i] == 'C') hasC = 1;
    }
    if (hasA) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'B' || S[i] == 'C' || S[i] == 'D' || S[i] == 'F') {
                S[i] = 'A';
            }
        }
    }
    else if (hasB) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'C' || S[i] == 'D' || S[i] == 'F') {
                S[i] = 'B';
            }
        }
    }
    else if (hasC) {
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == 'D' || S[i] == 'F') {
                S[i] = 'C';
            }
        }
    }
    else {
        for (int i = 0; i < S.length(); i++) {
            S[i] = 'A';
        }
    }
    cout << S;
    return 0;
}
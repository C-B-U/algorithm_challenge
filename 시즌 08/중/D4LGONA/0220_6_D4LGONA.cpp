#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isLucky(const string& s) 
{
    for (int i = 1; i < s.size(); ++i) 
    {
        if (s[i] == s[i - 1]) {
            return false;
        }
    }
    return true;
}

long long Search(string s) 
{
    sort(s.begin(), s.end());

    long long count = 0;
    do 
    {
        if (isLucky(s)) 
            count++;
    } while (next_permutation(s.begin(), s.end()));

    return count;
}

int main() {
    string S;
    cin >> S;

    long long result = Search(S);
    cout << result << endl;
}

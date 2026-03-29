#include <iostream>
#include <string>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    string num;
    int res = 0;

    bool minus = false;
    for (int i = 0; i < s.size(); ++i) 
    {
        if (s[i] == '+' || s[i] == '-') 
        {
            if (minus)
                res -= stoi(num);
            else
                res += stoi(num);

            num = "";

            if (s[i] == '-')
                minus = true;
        }
        else 
        {
            num += s[i];
        }

    }

    // 마지막값 연산
    if (minus)
        res -= stoi(num);
    else
        res += stoi(num);

    cout << res;
}

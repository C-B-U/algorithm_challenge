#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string code;
    int N;
    cin >> code >> N;

    vector<string> words(N);
    for (string& word : words)
    {
        cin >> word;
        for (int i = 0; i < 26; ++i)
        {
            for (char& c : word)
            {
                ++c;
                if (c > 'z')
                    c = 'a';
            }

            if (code.find(word) != string::npos)
            {
                for (char& c : code)
                    c = ((c - 'a') - (i + 1) + 26) % 26 + 'a';

                cout << code;
                return 0;
            }
        }
    }

    return 0;
}
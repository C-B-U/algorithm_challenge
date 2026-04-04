#include <iostream>

using namespace std;

int main() {
    int tc;
    int n, m;
    int a, b;

    cin >> tc;
    
    while(tc--){
        cin >> n >> m;

        while (m--){
            cin >> a >> b;
        }

        cout << n - 1 << "\n";
    }
    
    return 0;
}
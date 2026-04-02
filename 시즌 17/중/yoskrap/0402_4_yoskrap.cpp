#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int i;
    
    int n, m;
    cin >> n >> m;
    
    string title[n];
    int cut[n];
    for(i=0;i<n;i++)
        cin >> title[i] >> cut[i];
        
    int p[m];
    int index;
    for(i=0;i<m;i++){
        cin >> p[i];
        
        index = lower_bound(cut, cut+n, p[i]) - cut;
        cout << title[index] << '\n';
    }
    
    return 0;
}
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;
    bool answer = 0;
    
    while(S.size() < T.size()){
        if(T[T.size()-1] == 'A'){ // 'A'
            T = T.substr(0,T.size()-1);
        }
        else{ // 'B'
            T = T.substr(0,T.size()-1);
            reverse(T.begin(),T.end());
        }
    }
    if(S == T) answer = 1;
    cout << answer;

    return 0;
}

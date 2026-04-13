#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    long long int answer = 1;
    long long int sep = 1;
    while(T--){
        int temp;
        cin >> temp;
        if(temp == 0){
            cin >> temp;
            answer += temp;
        }
        else if(temp == 1){
            cin >> temp;
            answer *= temp;
            sep *= temp;
        }
        else if(temp == 2){
            cin >> temp;
            answer += (sep*temp);
        }
        else if(temp == 3){
            cout << answer << '\n';
        }
     }

    return 0;
}

#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    string str;
    cin >> N;
    cin >> str;

    if(N % 3 != 0){
        cout << "mix";
        return 0;
    }


    int Hcnt = 0;
    int HOcnt = 0;
    for(int i = 0; i < N; i++){ // left to right
        if(str[i] == 'O'){
            Hcnt--;
            HOcnt++;
        }

        else{ // H
            Hcnt++;
        }

        if(Hcnt < 0){
            cout << "mix";
            return 0;
        }
    }

    Hcnt = 0;
    HOcnt = 0;
    for(int i = N-1; i >= 0; i--){ // right to left
        if(str[i] == 'O'){
            Hcnt--;
            HOcnt++;
        }

        else{ // H
            Hcnt++;
        }

        if(Hcnt < 0){
            cout << "mix";
            return 0;
        }
    }

    if(HOcnt == Hcnt){
        cout << "pure";
        return 0;
    }
    cout << "mix";
    return 0;
}

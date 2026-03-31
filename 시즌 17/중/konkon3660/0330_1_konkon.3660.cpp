#include <iostream>
#include <cmath>
using namespace std;

int main(){
    unsigned long long N;
    int M;
    cin >> N >> M;
    
    if(N < M){
    unsigned long long int answer = 1;
    for(unsigned long long int i = 2; i <= N; i++){
        answer *= i;
        answer %= M;    
    }
    
    cout << answer;
    }
    else{
        cout << '0';
    }
}

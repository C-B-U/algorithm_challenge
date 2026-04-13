#include <iostream>
using namespace std;

int main(){
    int K;
    cin >> K;

    long long a[46];
    long long b[46];

    a[0] = 1;
    b[0] = 0;
    
    for(int i =1; i <= K; i++){
        a[i] = b[i-1];
        b[i] = a[i-1] + b[i-1];
    }
    cout << a[K] << " " << b[K];
    return 0;
}
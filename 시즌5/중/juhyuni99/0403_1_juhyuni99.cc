//https://www.acmicpc.net/problem/1978
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; // 수의 개수
    int cnt = 0; //소수의 개수
    cin >> N;
    vector<int> number(N);

    for (int i = 0; i < N; i++) {
        cin >> number[i]; 
        if (number[i] == 1) continue;
        
        //소수 판별
        bool is_prime = true;
        for (int j = 2; j * j <= number[i]; j++) { //2부터 N의 제곱근까지의 수 중에서 N이 나누어지는 수가 있는지 검사
            if (number[i] % j == 0) { //나누어지면 소수가 아니다.
                is_prime = false;
                break;
            }
        }
        if (is_prime) { 
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}

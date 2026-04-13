#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    cin >> N;
    vector<string> arr(N);
    vector<pair<int,int>> score_board(26,{0,0}); // point, index
    for(int i = 0; i < 26; i++){
        score_board[i].second = i;
    }
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        int array_size = arr[i].size();
        for(int ii = 0; ii < array_size; ii++){
            int alpha_num = arr[i][ii] - 'A';
            score_board[alpha_num].first += (int)pow(10,(array_size-ii-1)); // A?? 가 들어오면 A에 100만큼의 비중을 추가하는거임
        }
    }

    sort(score_board.begin(),score_board.end(),greater<pair<int,int>>());
    // 각 알파벳의 비중을 체크했으니까, 모든 알파벳이 어떤 수를 가질 때, 어느 정도의 비중을 갖는지 알 수 있음.
    // 아니 그냥 비중 큰 순서대로 9876543210 씩 주면 되는거 아님? 
    // 정렬마렵긴한데 정렬하면 원래 각 숫자가 어떤 알파벳을 가리키는지를 알 수가 없어지네...
    // 구조체로 명시할까?
    int answer = 0;
    for(int i = 1; i <= 10; i++){
        answer += score_board[i-1].first * (10 - i);
    }
    cout << answer;

    return 0;
}

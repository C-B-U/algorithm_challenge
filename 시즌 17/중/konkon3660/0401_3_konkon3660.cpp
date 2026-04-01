#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    // 각 동작의 시간복잡도.
    const int MOVE1_CNT = N;
    const int MOVE2_CNT = N / 2;
    const int MOVE3_CNT = (N / 2) + (N % 2);
    const int MOVE4_CNT = ((N - 1) / 3 ) + 1;
    
    // 가능한 모든 동작의 조합을 탐색.
    // 시간을 초과하는 경우는 제거.
    vector<int> answer_cnt;
    for(int i = 0; i < 16; i++){ //2^4 = 8 최대 경우의 수는 16
        int temp_cnt = 0b0000;
        int sum_time = 0;
        if(i & 0b1000){ 
            temp_cnt |= 0b1000;
            sum_time += MOVE1_CNT;
        }
        if(i & 0b0100){
            temp_cnt |= 0b0100;
            sum_time += MOVE2_CNT;
        }
        if(i & 0b0010){
            temp_cnt |= 0b0010;
            sum_time += MOVE3_CNT;
        }
        if(i & 0b0001){
            temp_cnt |= 0b0001;
            sum_time += MOVE4_CNT;
        }
        if(sum_time > M) continue;
        answer_cnt.push_back(temp_cnt);
    }

    set<vector<int>> states;
    for(auto i : answer_cnt) {
        vector<int> temp(min(6,N),1);
        for (int ii = 1; ii <= 6; ii++) { // 6이 최소공배수임.
            // 동작 1
            if (i & 0b1000) temp[ii - 1] = !temp[ii - 1];

            // 동작 2
            if ((i & 0b0100) && (ii % 2 == 0)) temp[ii - 1] = !temp[ii - 1];

            // 동작 3
            if ((i & 0b0010) && (ii % 2 != 0)) temp[ii - 1] = !temp[ii - 1];

            // 동작 4
            if ((i & 0b0001) && (ii % 3 == 1)) temp[ii - 1] = !temp[ii - 1];
        }
        states.insert(temp);
    }

    cout << states.size();
    return 0;
}

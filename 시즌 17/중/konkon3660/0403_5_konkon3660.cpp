#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{
    int x,y; // 격자판에서의 위치
    int num; // 빛의 번호
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,H;
    cin >> H >> N;
    // vector<vector<int>> gid(H,vector<int>(N,0)); //격자판 빛의 위치
    vector<Pos> lights;
    vector<int> answer(N);
    for(int i = 0; i < N; i++){
        Pos temp;
        cin >> temp.y >> temp.x;
        temp.num = i+1;
        lights.push_back(temp);

        // gid[temp.y-1][temp.x-1] = i+1;
    }

    sort(lights.begin(), lights.end(), [](const Pos& a, const Pos& b) { // x(오른쪽에 있는 빛) 기준으로 정렬.
        return a.x > b.x; 
    });

    cout << "YES\n"; // 좌우 길이는 무한하니 실패할 수가 없음.
    for(int i = 0; i < N; i++){ //
        Pos temp = lights[i];
        answer[temp.num-1] = N-i;
    }
    for(int ele : answer){
        cout << ele << ' ';
    }


    return 0;
}

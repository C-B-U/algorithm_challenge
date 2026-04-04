#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int res_idx = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= target) {
            res_idx = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return res_idx;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N,M;
    cin >> N >> M;
    vector<int> score;
    vector<string> how_score;
for (int i = 0; i < N; i++) {
        string name;
        int limit;
        cin >> name >> limit;
        how_score.push_back(name);
        score.push_back(limit);
    }
    for(int i = 0; i < M; i++){
        int a;
        cin >> a;
        int bin_result = binarySearch(score,a);
        cout << how_score[bin_result] << '\n';
    }
                
            

    return 0;
}

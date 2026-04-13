#include <iostream>
#include <vector>
using namespace std;

// int nton_sum(vector<int>& arr_sum, int start, int end){
//     return arr_sum[end+1] - arr_sum[start+1];
// }

bool is_avail_slicing_window(vector<long long int> &arr, vector<long long int> &arr_sum, int wsize, long long int K, long long int X) {
    int N = arr.size();
    
    for (int i = 0; i <= N - wsize; i++) {
        // 1. 앞부분 합
        long long int front_mon = arr_sum[i];
        
        // 2. 뒷부분 합
        long long int back_mon = arr_sum[N] - arr_sum[i + wsize];
        
        if ((front_mon * X) + back_mon >= K) {
            return true;
        }
    }
    return false;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long int N, K, X;
    cin >> N >> K >> X;
    vector<long long int> arr(N);
    vector<long long int> arr_sum(N+1,0);
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr_sum[i+1] = arr_sum[i] + arr[i];
    }

    int left = 1; // 못 일하는게 최대 일하는 수.
    int right = arr.size() - 1; // 하루만 일하는게 최대 일하는 수.
    int answer = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_avail_slicing_window(arr,arr_sum,mid, K, X)){
            left = mid + 1;
            answer = mid;
        }
        else
            right = mid - 1;
    }

    cout << answer;



    return 0;
}

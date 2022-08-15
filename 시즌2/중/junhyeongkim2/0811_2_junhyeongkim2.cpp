#include <iostream>
#include <algorithm>
using namespace std;

int arr[1500*1500];
int n;


int main(){

    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0 ; i < n*n;i++){
        cin >> arr[i];
    }
    sort(arr,arr+n*n);
    cout << arr[n*n-n];



}
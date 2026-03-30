#include <iostream>

using namespace std;

int dp[1001][3];
int n ;

int main(){
    cin >> n ;

    int a1, a2, a3;

    cin >> a1 >> a2 >> a3;
    dp[0][0] = a1;
    dp[0][1] = a2;
    dp[0][2] = a3;

    for(int i = 1 ; i < n ; i ++){
        int r , g , b;
        cin >> r >> g >> b;
        dp[i][0] = dp[i][0]+min(dp[i-1][1],dp[i-1][2]) + r;
        dp[i][1] = dp[i][1]+min(dp[i-1][0],dp[i-1][2]) + g;
        dp[i][2] = dp[i][2]+min(dp[i-1][0],dp[i-1][1]) + b;

/*
        cout << dp[i][0] << "\n";
        cout << dp[i][1] << "\n";
        cout << dp[i][2] << "\n";
*/
    }

    cout << min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));







}


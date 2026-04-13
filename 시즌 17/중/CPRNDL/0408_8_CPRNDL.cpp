#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int days, bonus;
    ll ticket;
    cin >> days >> ticket >> bonus;
    
    vector<long long> pay(days);

    for (int i = 0; i < days; i++) {
        cin >> pay[i];
    }
    
    // prefix[i] = a[0] + a[1] + ... + a[i-1] (prefix[0] = 0)
    vector<ll> sum_pay(days + 1, 0);
    for (int i = 0; i < days; i++) {
        sum_pay[i + 1] = sum_pay[i] + pay[i];
    }
    
    ll total = sum_pay[days]; // 전체 일급 합
    
    // 휴가 길이가 len일 때 가능한지 확인하는 함수
    // 수입 = 휴가 전 수입 + 휴가 후 수입
    auto is_possible = [&](int len) -> bool {
        for (int l = 0; l <= days - len; l++) {
            int r = l + len;
            
            // 휴가 전 수입: 보너스 적용
            // 휴가 후 수입: 그냥 일급
            ll earn = sum_pay[l] * bonus + (total - sum_pay[r]);
            
            if (earn >= ticket) {
                return true;    // 가능
            }
        }
        return false;   // 불가능
    };
    
    int lo = 1, hi = days;
    int ans = -1;
    
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        
        if (is_possible(mid)) {
            ans = mid;  // 더 긴 휴가
            lo = mid + 1;
        } else {
            hi = mid - 1; // 더 짧은 휴가
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}
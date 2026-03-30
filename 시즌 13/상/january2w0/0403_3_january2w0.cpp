#include <iostream>
#include <vector>

using namespace std;

struct Floor { int L, R; };

int main()
{
    int i, N, H, W, maxH = 0;
    cin >> N >> H >> W;

    vector<Floor> floors, rooms(H+1, { W+1, 0 });
    rooms[1] = { 1, 1 };

    while (N--) {
        int X, Y;
        cin >> X >> Y;
        rooms[X].L = min(rooms[X].L, Y);
        rooms[X].R = max(rooms[X].R, Y);
        maxH = max(X, maxH);
    }

    for (i = 1; i <= H; i++) {
        if (rooms[i].R) floors.push_back({ rooms[i].L, rooms[i].R });
    }

    int M = floors.size();
    vector<Floor> dp(M);

    int L0 = floors[0].L, R0 = floors[0].R;
    dp[0].L = R0 - 1 + (R0 - L0);
    dp[0].R = R0 - 1;

    for (i = 1; i < M; i++)
    {
        int l = floors[i-1].L, r = floors[i-1].R;
        int L = floors[i].L, R = floors[i].R;

        dp[i].L = min(dp[i-1].L + abs(l - R), dp[i-1].R + abs(r - R)) + (R - L);
        dp[i].R = min(dp[i-1].L + abs(l - L), dp[i-1].R + abs(r - L)) + (R - L);
    }

    cout << 100*(maxH - 1) + min(dp.back().L, dp.back().R);

    return 0;
}

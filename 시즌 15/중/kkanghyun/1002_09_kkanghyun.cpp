#include <iostream>
using namespace std;

size_t minScore[100'001][4];
size_t maxScore[100'001][4];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    cin >> minScore[1][1] >> minScore[1][2] >> minScore[1][3];
    maxScore[1][1] = minScore[1][1];
    maxScore[1][2] = minScore[1][2];
    maxScore[1][3] = minScore[1][3];

    int arr[4];
    for (int i = 2; i <= N; ++i)
    {
        cin >> arr[1] >> arr[2] >> arr[3];

        minScore[i][1] = min(minScore[i - 1][1] + arr[1], minScore[i - 1][2] + arr[1]);
        minScore[i][2] = min(minScore[i - 1][1] + arr[2], min(minScore[i - 1][2] + arr[2], minScore[i - 1][3] + arr[2]));
        minScore[i][3] = min(minScore[i - 1][2] + arr[3], minScore[i - 1][3] + arr[3]);

        maxScore[i][1] = max(maxScore[i - 1][1] + arr[1], maxScore[i - 1][2] + arr[1]);
        maxScore[i][2] = max(maxScore[i - 1][1] + arr[2], max(maxScore[i - 1][2] + arr[2], maxScore[i - 1][3] + arr[2]));
        maxScore[i][3] = max(maxScore[i - 1][2] + arr[3], maxScore[i - 1][3] + arr[3]);
    }

    cout << max(maxScore[N][1], max(maxScore[N][2], maxScore[N][3])) << " " << min(minScore[N][1], min(minScore[N][2], minScore[N][3]));
}
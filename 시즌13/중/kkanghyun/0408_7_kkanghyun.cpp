#include <iostream>
using namespace std;

// nCr ���
double Comb(int n, int r) 
{
    if (r > n || r < 0) 
        return 0;

    double res = 1;
    for (int i = 1; i <= r; ++i) 
    {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main() 
{
    int N, M, K;
    cin >> N >> M >> K;

    double total = Comb(N, M);
    double win = 0;

    // K������ M������ ������ ���� ��� ����� �� ���
    for (int k = K; k <= M; ++k) 
    {
        win += Comb(M, k) * Comb(N - M, M - k);
    }

    cout.precision(10);
    cout << win / total << endl;
}
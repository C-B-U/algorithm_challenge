#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M, tmp;
	vector<int> W_limit;
	vector<int> B_weight;
	vector<int> result;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> tmp;
		W_limit.emplace_back(tmp);
	}
	result.assign(N, 0);
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> tmp;
		B_weight.emplace_back(tmp);
	}

	if (*max_element(W_limit.begin(), W_limit.end()) < *max_element(B_weight.begin(), B_weight.end())) // 아예 못담는 경우
	{
		cout << "-1" << endl;
		return 0;
	}

	sort(W_limit.begin(), W_limit.end());
	sort(B_weight.begin(), B_weight.end());

	do
	{
		for (int i = W_limit.size() - 1; i >= 0; --i) 
		{
			for (int j = B_weight.size() - 1; j >= 0; --j) 
			{
				if (W_limit[i] >= B_weight[j]) 
				{
					result[i]++;
					B_weight.erase(B_weight.begin() + j);
					break; // 이 부분을 추가하여 내부 루프를 종료합니다.
				}
			}
		}
	} while (B_weight.size() != 0);

	cout << *max_element(result.begin(), result.end()) << endl;

}
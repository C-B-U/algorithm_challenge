#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int K;
	cin >> K;

	std::vector<std::vector<int>> v;
	for (int i = 0; i < K; ++i) {
		int N;
		cin >> N;

		std::vector<int> scores;
		for (int j = 0; j < N; ++j) {
			int score;
			cin >> score;
			scores.push_back(score);
		}
		sort(scores.begin(), scores.end(), greater<int>());
		v.push_back(scores);
	}

	for (int i = 0; i < v.size(); ++i) {
		int max = v[i].front();
		int min = v[i].back();
		int largestGap{};
		for (int j = 0; j < v[i].size() - 1; ++j) {
			int gap = v[i][j] - v[i][j + 1];
			if (gap > largestGap)
				largestGap = gap;
		}
		cout << "Class " << i + 1 << endl;
		cout << "Max " << max << ", Min " << min << ", Largest gap " << largestGap << endl;
	}
}
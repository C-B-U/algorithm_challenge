#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char *argv[])
{
	int p, c;
	int V, E;
	int A, B, C;
	int parent[10010];
	long long weightSum = 0;
	priority_queue<pair<int, pair<int, int> > > pq;
	
	memset(parent, 0, sizeof(parent));

	scanf("%d", &V);
	scanf("%d", &E);

	for (int i = 1; i <= V; ++i) {
		parent[i] = i;
	}

	for (int i = 1; i <= E; ++i) {
		scanf("%d", &A);
		scanf("%d", &B);
		scanf("%d", &C);

		pq.push(make_pair(-C, make_pair(A, B)));
	}

	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;

		p = min(parent[a], parent[b]);
		c = max(parent[a], parent[b]);

		if (p == c) {
			pq.pop();
			continue;
		}

		for (int i = 1; i <= V; ++i) {
			if (parent[i] == c) {
				parent[i] = p;
			}
		}

		weightSum += -pq.top().first;
		pq.pop();
	}

	printf("%lld\n", weightSum);

	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
	int node[2];
	int distance;
};

int GetParent(vector<int>& v, int idx)
{
	if (v[idx] == idx)
		return idx;

	v[idx] = GetParent(v, v[idx]);

	return v[idx];
}

void UnionParent(vector<int>& v, int a, int b)
{
	a = GetParent(v, a);
	b = GetParent(v, b);
	v[b] = a;
}

bool Find(vector<int>& v, int a, int b)
{
	a = GetParent(v, a);
	b = GetParent(v, b);

	if (a == b)
		return true;

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, E;
	cin >> V >> E;

	vector<int> vecVertex;
	vecVertex.resize(V + 1);
	for (int i = 1; i <= V; ++i)
	{
		vecVertex[i] = i;
	}

	vector<Edge> vecEdge;
	vecEdge.reserve(E);
	for (int i = 0; i < E; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;

		Edge edge;
		edge.node[0] = A;
		edge.node[1] = B;
		edge.distance = C;
		vecEdge.push_back(edge);
	}

	sort(vecEdge.begin(), vecEdge.end(), [](const Edge& a, const Edge& b) {
		return a.distance < b.distance;
		});

	int sum{};
	for (int i = 0; i < vecEdge.size(); ++i)
	{
		if (!Find(vecVertex, vecEdge[i].node[0] - 1, vecEdge[i].node[1] - 1))
		{
			sum += vecEdge[i].distance;
			UnionParent(vecVertex, vecEdge[i].node[0] - 1, vecEdge[i].node[1] - 1);
		}
	}

	cout << sum;
}
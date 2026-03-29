#include<iostream>
#include<algorithm>
using namespace std;
typedef struct point{
	int num,x, y, v;
};
point pointList[100000];
bool more_faster(point first,point second) {
	double first_DurationOfTime = (first.x * first.x + first.y * first.y) / double(first.v*first.v), second_DurationOfTime =(second.x * second.x + second.y * second.y) / double(second.v*second.v);
	if (first_DurationOfTime == second_DurationOfTime) {
		return first.num < second.num;
	}
	else return first_DurationOfTime < second_DurationOfTime;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		pointList[i].num = i + 1;
		cin >> pointList[i].x >> pointList[i].y >> pointList[i].v;
	}
	sort(pointList, pointList + N, more_faster);
	for (int i = 0; i < N; i++)cout << pointList[i].num<<'\n';
	return 0;
}

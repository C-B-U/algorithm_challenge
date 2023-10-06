#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    Point p[3];

    for (int i = 0; i < 3; i++)
        cin >> p[i].x >> p[i].y;

    int ccw = (p[1].x - p[0].x) * (p[2].y - p[0].y) - (p[1].y - p[0].y) * (p[2].x - p[0].x);
    if (ccw != 0) ccw = ccw / abs(ccw);

    cout << ccw << endl;
}

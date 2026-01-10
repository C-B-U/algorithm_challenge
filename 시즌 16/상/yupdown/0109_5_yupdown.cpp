#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define FASTIO() cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

template <typename T>
struct vector2d
{
    T x, y;

    vector2d() : vector2d(0, 0) {}
    vector2d(T x, T y) : x(x), y(y) {}
    vector2d(const vector2d& rhs) : x(rhs.x), y(rhs.y) {}
    template <typename TR>
    vector2d(const vector2d<TR>& rhs) : x(static_cast<T>(rhs.x)), y(static_cast<T>(rhs.y)) {}

    T sqr_magnitude() const { return x * x + y * y; }
    T magnitude() const { return sqrt(sqr_magnitude()); }
    static T dot(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.x + lhs.y * rhs.y; }
    static T cross(const vector2d& lhs, const vector2d& rhs) { return lhs.x * rhs.y - lhs.y * rhs.x; }

    vector2d operator+(const vector2d& other) const { return vector2d(x + other.x, y + other.y); }
    vector2d operator-(const vector2d& other) const { return vector2d(x - other.x, y - other.y); }
    vector2d operator+() const { return vector2d(x, y); }
    vector2d operator-() const { return vector2d(-x, -y); }
    vector2d operator*(const T& scalar) const { return vector2d(x * scalar, y * scalar); }
    vector2d operator/(const T& scalar) const { return vector2d(x / scalar, y / scalar); }
    vector2d& operator+=(const vector2d& other) { x += other.x; y += other.y; return *this; }
    vector2d& operator-=(const vector2d& other) { x -= other.x; y -= other.y; return *this; }
    vector2d& operator*=(const T& scalar) { x *= scalar; y *= scalar; return *this; }
    vector2d& operator/=(const T& scalar) { x /= scalar; y /= scalar; return *this; }
    bool operator==(const vector2d& other) const { return x == other.x && y == other.y; }
    bool operator!=(const vector2d& other) const { return x != other.x || y != other.y; }
    bool operator<(const vector2d& other) const { return x < other.x || (x == other.x && y < other.y); }
    bool operator>(const vector2d& other) const { return x > other.x || (x == other.x && y > other.y); }
    bool operator<=(const vector2d& other) const { return x <= other.x && y <= other.y; }
    bool operator>=(const vector2d& other) const { return x >= other.x && y >= other.y; }
};

using vector2df = vector2d<double>;
pair<vector2df, vector2df> table[10000];

int main()
{
    FASTIO();
    int n;
    cin >> n;
    vector2df p1, p2;
    for (int i = 0; i < n; ++i) {
        int t1, t2;
        cin >> t1 >> t2;
        table[i].first = {
            cos(M_PI * t1 / 1800) * 1000,
            sin(M_PI * t1 / 1800) * 1000
        };
        table[i].second = {
            cos(M_PI * t2 / 1800) * 1000,
            sin(M_PI * t2 / 1800) * 1000
        };
    }
    int t1, r1, t2, r2;
    cin >> t1 >> r1 >> t2 >> r2;
    p1 = {
        cos(M_PI * t1 / 1800) * r1,
        sin(M_PI * t1 / 1800) * r1
    };
    p2 = {
        cos(M_PI * t2 / 1800) * r2,
        sin(M_PI * t2 / 1800) * r2
    };
    int intersectCnt = 0;
    for (int i = 0; i < n; ++i) {
        double c1 = vector2df::cross(p2 - p1, table[i].first - p1);
        double c2 = vector2df::cross(p2 - p1, table[i].second - p1);
        double c3 = vector2df::cross(table[i].second - table[i].first, p1 - table[i].first);
        double c4 = vector2df::cross(table[i].second - table[i].first, p2 - table[i].first);
        if (c1 * c2 < 0 && c3 * c4 < 0) {
            intersectCnt++;
        }
    }
    cout << (intersectCnt & 1 ? "NO" : "YES");
}
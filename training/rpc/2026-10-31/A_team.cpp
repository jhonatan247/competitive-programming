#include<bits/stdc++.h>
using namespace std;
using int64 = int64_t;
using uint64 = uint64_t;
using f64 = long double;
using Point = pair<f64,f64>;

Point operator*(const Point& p, f64 k) {
    return {p.first * k, p.second * k};
}

Point operator+(Point& a, Point& b) {
    return {a.first + b.first, a.second + b.second};
}

Point operator-(Point& a, Point& b) {
    return {a.first - b.first, a.second - b.second};
}

f64 dot_prod(Point a, Point b) {
    return a.first * b.first + a.second * b.second;
}

f64 norm(Point v) {
    return sqrt(v.first * v.first + v.second * v.second);    
}

double optimal_case1(Point a, Point b, Point c) {
    // a is moved to the line passing by b orthogonal to [b,c]
    Point v = c - b;
    return abs(dot_prod(b - a, v) / norm(v));
}

double optimal_case2(Point a, Point b, Point c) {
    // a is moved to the circunference with diameter [b,c]
    Point center = (c + b) * 0.5;
    f64 radious = norm(c - b) / 2;
    return abs(norm(a - center) - radious);
}

double find_optimal(Point a, Point b, Point c) {
    f64 opt1 = optimal_case1(a,b,c);
    f64 opt2 = optimal_case2(a,b,c);
    return min(opt1,opt2);
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    cout.setf(ios::fixed, ios::floatfield);
    Point a,b,c;
    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> c.first >> c.second;

    f64 ans = min({
        find_optimal(a,b,c),
        find_optimal(b,c,a),
        find_optimal(c,a,b),
    });
    
    cout << ans << '\n';
    
    return 0;
}
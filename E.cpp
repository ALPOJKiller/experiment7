#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;
typedef pair<unsigned, unsigned> Point;

bool dominate(Point a, Point b) {
    return a.first >= b.first && a.second >= b.second;
}

int main() {
    size_t n;
    while (cin >> n) {
        set<Point> points;
        for (size_t i = 0; i < n; ++i) {
            unsigned x, y;
            cin >> x >> y;
            auto point = make_pair(x, y);
            bool is_big = true;
            for (auto it = points.begin(); it != points.end();) {
                if (dominate(point, *it)) {
                    it = points.erase(it);
                } else if (dominate(*it, point)) {
                    is_big = false;
                    break;
                } else {
                    it++;
                }
            }
            if (is_big) {
                points.insert(point);
            }
        }
        bool is_first = true;
        for (auto pt : points) {
            if (!is_first)
                cout << ',';
            is_first = false;
            cout << '(' << pt.first << ',' << pt.second << ')';
        }
        cout << endl;
    }
    return 0;
}
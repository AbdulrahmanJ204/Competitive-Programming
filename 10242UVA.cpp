#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);

struct point {
    double x, y;
};
bool cmp(point p1, point p2) {
    return p1.x == p2.x && p1.y == p2.y;
}
int main() {
    InTheNameOfAllah
        point p1,
        p2, p3, p4;
    while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {
        if (p1.y > p2.y)
            swap(p1, p2);
        
        double dx = p2.x - p1.x, dy = p2.y - p1.y;
        cout << fixed << setprecision(3);
        if (cmp(p3, p1)) {
            p4.x += dx;
            p4.y += dy;
            cout << p4.x << ' ' << p4.y << endl;
        } else if (cmp(p3, p2)) {
            p4.x -= dx;
            p4.y -= dy;
            cout << p4.x << ' ' << p4.y << endl;
        } else {
          swap(p3,p4);
          if (cmp(p3, p1)) {
            p4.x += dx;
            p4.y += dy;
            cout << p4.x << ' ' << p4.y << endl;
        } else if (cmp(p3, p2)) {
            p4.x -= dx;
            p4.y -= dy;
            cout << p4.x << ' ' << p4.y << endl;
        } 
        }
        
    }
    return 0;
}
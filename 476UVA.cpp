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
struct rect {
    double x1, x2, y1, y2;
};
int main() {
    InTheNameOfAllah
        vector<rect>
            v;
    char c;
    while (cin >> c && c != '*') {
        rect r;
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        v.push_back(r);
    }
    int cnt = 0;
    double x, y;
    while (cin >> x >> y && !(x == 9999.9 && y == 9999.9)) {
        cnt++;
        bool contained = false;
        int counter = 0;
        for (auto r : v) {
            counter++;
            if (x > r.x1 && x < r.x2 && y < r.y1 && y > r.y2) {
                contained = true;
                cout << "Point " << cnt << " is contained in figure " << counter << endl;
            }
        }
        if (!contained)
            cout << "Point " << cnt << " is not contained in any figure\n";
    }

    return 0;
}
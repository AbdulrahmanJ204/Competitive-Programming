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
ll d1, d2, r1, r2, c1, c2;
bool check(int x) {
    int w = r1 - x,
        y = c1 - x,
        z = d1 - x;
    if (z > 9 || y > 9 || w > 9 || z <= 0 || y <= 0 || w <= 0)
        return false;
    return c2 == w + z &&
           r2 == y + z &&
           d2 == w + y &&
           x != w &&
           x != z &&
           x != y &&
           y != w &&
           y != z &&
           w != z;
}
void solve() {
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    for (int i = 1; i < 10; i++) {
        if (check(i)) {
            cout << i << ' ' << r1 - i << endl;
            cout << c1 - i << ' ' << d1 - i << endl;
            return;
        }
    }
    cout << -1 << endl;

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        // cendl;
    }
    return 0;
}
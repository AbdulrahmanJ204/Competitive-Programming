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

void solve() {

    ll n, d, m, x, y;
    cin >> n >> m >> x >> y >> d;
    if (x + d >= n && x - d <= 1)
        cout << -1;
    else if (x - d <= 1 && y - d <= 1)
        cout << -1;
    else if (x + d >= n && y + d >= m)
        cout << -1;
    else if (y + d >= m && y - d <= 1)
        cout << -1;
    else
        cout << n + m - 2;
    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
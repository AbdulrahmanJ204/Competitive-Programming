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
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
    ll x, y, m;
    cin >> x >> y >> m;
    ll ans = 0;
    for (ll i = 0; i <= m; i++) {
        for (ll j = 0; j <= m; j++) {
            ll temp = i * x + y * j;
            if (temp <= m)
                ans = max(ans, temp);
        }
    }
    cout << ans;

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
        cendl;
    }
    return 0;
}
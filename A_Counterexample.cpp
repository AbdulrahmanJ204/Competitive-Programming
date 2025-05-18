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

bool co(ll a, ll b) {
    return __gcd(a, b) == 1;
}
void solve() {
    ll l, r;
    cin >> l >> r;
    for (ll i = l; i <= r - 2; i++)
        for (ll j = i + 1; j <= r - 1; j++)
            for (ll k = j + 1; k <= r; k++)
                if (co(i, j) && co(j, k) && !co(i, k)) {
                    cout << i << " " << j << ' ' << k;
                    return;
                }

    cout << -1;

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
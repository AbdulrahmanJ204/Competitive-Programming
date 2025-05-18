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
    ll n, m;
    cin >> n >> m;
    ll a[5], b[5];
    for (ll i = 0; i < 5; i++)
        a[i] = b[i] = 0;
    ll x = n / 5;
    for (ll i = 0; i < 5; i++)
        a[i] += x;
    for (ll i = x * 5 + 1; i <= n; i++)
        a[i % 5]++;
    x = m / 5;
    for (ll i = 0; i < 5; i++)
        b[i] += x;
    for (ll i = x * 5 + 1; i <= m; i++)
        b[i % 5]++;
    ll ans = 0;
    for (ll i = 1; i < 5; i++)
        ans += a[i] * b[5 - i];

    ans += a[0] * b[0];

    // for (ll i = 0; i < 5; i++)
    //     cout << a[i] << ' ';
    // cendl;
    // for (ll i = 0; i < 5; i++)
    //     cout << b[i] << ' ';
    // cendl;

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
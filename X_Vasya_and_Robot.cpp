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
    ll n;
    cin >> n;
    int l, r, ql, qr;
    cin >> l >> r >> ql >> qr;
    int w[n + 1], pre[n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        pre[i] = w[i];
    }
    if (n == 1) {
        cout << min(l * w[1], r * w[1]);
        return;
    }
    for (int i = 1; i < n + 1; i++)
        pre[i] += pre[i - 1];

    ll ans = 1e9;
    for (int i = 0; i <= n; i++) {
        ll ansL = 0, ansR = 0, repeated = 0;
        ansL = l * pre[i];
        ansR = r * (pre[n] - pre[i]);
        if (i > n - i)
            repeated = (2*i-n-1) * ql;
        else if (i < n - i)
            repeated = qr * (n- 2*i-1);
        ans = min(ans, ansL + ansR + repeated);
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
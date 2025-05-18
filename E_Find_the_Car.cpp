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
    ll n, k, q;
    cin >> n >> k >> q;
    ll x[k + 1], t[k + 1];
    x[0] = t[0] = 0;
    for (int i = 1; i < k + 1; i++)
        cin >> x[i];

    for (int i = 1; i < k + 1; i++)
        cin >> t[i];

    while (q--) {
        ll d;
        cin >> d;
        int index = upper_bound(x, x + k + 1, d) - x - 1;
        if (index == k)
            cout << t[k] << ' ';
        else {
            ll mdx = x[index + 1] - x[index];
            if (mdx == 0) {
                cout << t[index] << ' ';
                continue;
            }
            ll dx = d - x[index];
            ll dt = dx * (t[index + 1] - t[index]) / mdx;
            ll ans = t[index] + dt;
            cout << ans << ' ';
        }
    }

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
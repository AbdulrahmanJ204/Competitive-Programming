#include <bits/stdc++.h>
using namespace std;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define ll long long
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define endl '\n'
#define cendl cout << endl
#define cyes cout << "YES" << endl
#define cno cout << "NO" << endl
#define cin(v)                        \
    for (ll i = 0; i < v.size(); i++) \
        cin >> v[i];
#define unq(v) v.resize(distance(v.begin(), unique(all(v))));
#define tryAndCry(v)      \
    for (auto x : v) {    \
        cout << x << " "; \
    }                     \
    cout << "\n";
#define InTheNameOfAllah          \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
ll n, x;
const int M = 60;
ll c[M], h[M];
ll fun(int i, ll money) {
    if (i == n)
        return 0;
    ll c1 = 0, c2;
    if (money >= c[i] || c[i] == 0) {
        c1 = h[i] + fun(i + 1, money - c[i] + x);
    }
    c2 = fun(i + 1, money + x);
    return max(c1, c2);
}

void solve() {
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> h[i];
    }

    cout << fun(0, 0);
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
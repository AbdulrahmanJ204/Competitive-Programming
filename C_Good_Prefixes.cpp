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

void solve() {
    ll n;
    cin >> n;
    n++;
    ll a[n], pre[n], mx[n];
    pre[0] = a[0] = mx[0] = 0;
    ll m = 0;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        m = max(a[i], m);
        pre[i] = a[i] + pre[i - 1];
        mx[i] = m;
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        // cout<<pre[i]<<" "<<mx[i]<<endl;
        if (pre[i] == 2 * mx[i])
            ans++;
    }
    cout << ans;
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
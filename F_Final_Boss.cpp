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
ll n, h;
const int M = 2e5 + 10;
ll a[M], c[M];
ll s = 0;
bool check(ll mid) {
    ll sum = s;
    for (int i = 0; i < n; i++) {
        sum += ((mid - 1) / c[i] * a[i]);
        if(sum>=h) return true;
    }
    // if (mid == 19999800001)
    // cout << "MID: " << mid << " sum: " << sum << "  H : " << h << endl;
    return sum >= h;
}
void solve() {
    cin >> h >> n;
    s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    if (s >= h) {
        cout << 1;
        return;
    }
    ll ans = 1e18, l = -1, r = 1e12;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            ans = min(mid, ans);
            r = mid - 1;
        } else
            l = mid + 1;
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
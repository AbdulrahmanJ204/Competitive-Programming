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

ll fun(ll len) {
    ll ans = 0, l = 0, r = 1e9;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (mid * mid >= len) {
            ans = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }
    return ans;
}

void solve() {
    ll r,ans;
    cin >> r;
    ans = 0;
    for (ll i = 0; i <= r; i++) {
        ll mn = r * r - i * i;
        ll mx = (r + 1) * (r + 1) - i * i;

        mn = fun(mn);
        mx = fun(mx);
        ans += (mx - mn) * 4;
        if (!mn)
            ans-=4;
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
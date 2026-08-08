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
    ll n, q;
    cin >> n >> q;
    ll a[n + 1], pre[n + 1], repeated[n + 1];
    a[0] = 0;
    repeated[0] = 0;
    pre[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = a[i];
        repeated[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        pre[i] += pre[i - 1];
    }
    map<ll, ll> m;
    ll mx = 0;
    for (int i = 1; i < n + 1; i++) {
        repeated[i]=repeated[i-1]+(a[i]==1);
    }
    // for(auto x: pre) cout<<x<<' ';cendl;
    // for(auto x: repeated) cout<<x<<' ';cendl;
    while (q--) {
        ll l, r;
        cin >> l >> r;
        ll sum = pre[r] - pre[l - 1];
        ll len = r - l + 1;
        if (sum == len || r == l) {
            cout << "NO" << endl;
            continue;
        }
        ll numberOfAllowed = sum - len;
        ll numberOfRepeated = repeated[r]-repeated[l-1];
        if (numberOfAllowed < numberOfRepeated)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    cin >> t;
    while (t--) {
        solve();
        // cendl;
    }
    return 0;
}
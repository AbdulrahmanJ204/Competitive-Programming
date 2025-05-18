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
    ll a[n];
    map<ll, ll> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    vector<ll> v;
    for (auto x : m)
        v.push_back(x.first);
    sort(v.begin(), v.end());
    ll ans = 0;
    ll two32 = 2147483647;
    for (int i = 0; i < v.size(); i++) {
        if (m[v[i]] <= 0)
            continue;
        ll x = two32 - v[i];
        int index = lower_bound(v.begin(), v.end(), x) - v.begin();

        if (index >= v.size()) {
            ans += m[v[i]];
            m[v[i]] = 0;
        } else if (x == v[index]) {
            ans += max(m[v[i]], m[v[index]]);
            m[v[index]] = 0;
            m[v[i]] = 0;
        } else {
            ans += m[v[i]];
            m[v[i]] = 0;
        }
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
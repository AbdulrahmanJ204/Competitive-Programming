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
    ll n, k;
    cin >> n >> k;
    int a[n];
    int mn = 1e9, mx = 0;
    ;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(a[i], mx);
    }
    int color = 1;
    vector<int> v[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < mn; j++) {
            v[i].push_back(color);
        }
    }
    if (mx - mn > k) {
        cno;
        return;
    }
    while (color <= k) {
        for (int i = 0; i < n; i++) {
            v[i].push_back(color);
        }
        color++;
    }

    cyes;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << v[i][j] << ' ';
        }
        cendl;
    }

    return;
}

int main() {
    InTheNameOfAllah
        ll t = 1;
    // cin>>t;
    while (t--) {
        solve();
    }
    return 0;
}
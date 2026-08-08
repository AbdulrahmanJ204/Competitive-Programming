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
    int k, n;
    cin >> n >> k;
    int a[n];
    int mx = -1e9 - 7, mn = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        mn = min(a[i], mn);
    }
    if (k > 2)
        cout << mx;
    else if (k == 2)
        cout << max(a[0], a[n - 1]);
    else
        cout << mn;
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
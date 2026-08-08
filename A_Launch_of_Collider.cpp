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
    string s;
    cin >> s;
    ll x[n];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    string temp = s;
    ll ans = 1e18;
    for (int i = 0; i < n - 1; i++)
        if (s[i] == 'R' && s[i + 1] == 'L')
            ans = min(ans, (x[i + 1] - x[i]) / 2);

    ans == 1e18 ? cout << -1 : cout << ans;

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
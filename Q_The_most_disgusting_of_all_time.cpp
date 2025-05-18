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
    int br = 0, rb = 0, b = 0, r = 0, ro = 0, re = 0, bo = 0, be = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'r') {
            if (i % 2 == 0)
                re++;
            else
                ro++;
            r++;
        } else if (i % 2 == 0)
            be++;
        else
            bo++;
        b++;
    }
    int ans = 1e9;
    // cout << n - re - bo << ' ' << n - ro - be << endl;
    ans=min(max(re,bo),max(ro,be));

    cout << ans;
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
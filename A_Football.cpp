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
    map<string, int> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s]++;
    }
    string ans = ""; int d = 0;
    for (auto x : m) {
        if (ans == "")
            ans = x.first;
        else if (x.second > d)
            ans = x.first;
        d = x.second;
    }
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
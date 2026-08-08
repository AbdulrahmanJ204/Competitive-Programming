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
    s = "." + s;
    n++;
    int r1 = -1, r2 = -1, l1 = -1, l2 = -1;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'R') {
            if (r1 == -1)
                r1 = i;
            r2 = i;
        }
        if (s[i] == 'L') {
            if (l1 == -1)
                l1 = i;
            l2 = i;
        }
    }
    if (r1 != -1)
        cout << r2 << " " << r2 + 1;
    else
        cout << l1 << " " << l1 - 1;
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
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
    int x;
    cin >> x;
    bool can = true;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a + x == 7 || b + x == 7||b==x||a==x)
            can = false;
    }
    can ? cout << "YES" : cout << "NO";

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
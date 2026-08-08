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
    ll x;
    cin >> x;
    ll ans = 0, index = 1;
    for (ll y = 1; y < x; y++) {
        if (__gcd(x, y) + y >= ans) {
            ans = __gcd(x, y) + y;
            index = y;
        }
    }
    cout << index;

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
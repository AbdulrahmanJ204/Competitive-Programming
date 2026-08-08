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
    ll a, b;
    cin >> a >> b;
    ll ml = a - 1, mr = n - b;
    if (n / 2 - ml < mr - n / 2 || n / 2 - mr < ml - n / 2)
        cout << -1;
    else
        cout << 'w';
    vector<int> l, r;
    l.push_back(a);
    r.push_back(b);

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
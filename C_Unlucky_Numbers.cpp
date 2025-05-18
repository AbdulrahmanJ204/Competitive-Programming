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
    ll l, r;
    cin >> l >> r;
    if (l == r) {
        cout << l;
        return;
    }
    string a, b;
    a = to_string(l);
    b = to_string(r);
    if (b.size() > a.size()) {
        cout << string(a.size(), '9');
        return;
    }
    string ans = "";

    int size = a.size();
    for (int i = 0; i < size; i++) {
        if (b[i] - a[i] >= 2) {
            char c = (a[i] + 1);
            // cout<<c<<endl<<endl;
            while (i < size) {
                ans += c;
                i++;
            }
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
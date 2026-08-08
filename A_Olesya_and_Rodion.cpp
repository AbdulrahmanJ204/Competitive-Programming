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
    int n, t;
    cin >> n >> t;
    if (n == 1) {
        t == 10 ? cout << -1 : cout << t;
    } else if (t == 10) {
        for (int i = 0; i < n - 1; i++)
            {cout << 1;}
        cout << 0;
    } else {
        for (int i = 0; i < n; i++)
            cout << t;
    }

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